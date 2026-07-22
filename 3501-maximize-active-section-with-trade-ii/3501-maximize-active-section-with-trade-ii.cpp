struct Group {
  int start;
  int length;
};

class SegmentTree {
 public:
  SegmentTree(const vector<int>& values) {
    size = 1;
    while (size < values.size())
      size <<= 1;

    tree.assign(size * 2, 0);

    for (int i = 0; i < values.size(); ++i)
      tree[size + i] = values[i];

    for (int i = size - 1; i > 0; --i)
      tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
  }

  int query(int left, int right) const {
    left += size;
    right += size;

    int result = 0;

    while (left <= right) {
      if (left & 1)
        result = max(result, tree[left++]);

      if (!(right & 1))
        result = max(result, tree[right--]);

      left >>= 1;
      right >>= 1;
    }

    return result;
  }

 private:
  int size;
  vector<int> tree;
};

class Solution {
 public:
  vector<int> maxActiveSectionsAfterTrade(
      string s, vector<vector<int>>& queries) {
    int ones = 0;

    for (char c : s)
      ones += c == '1';

    vector<Group> groups;
    vector<int> groupIndex(s.size(), -1);

    for (int i = 0; i < s.size();) {
      if (s[i] == '1') {
        groupIndex[i] = groups.empty() ? -1 : groups.size() - 1;
        ++i;
        continue;
      }

      int start = i;

      while (i < s.size() && s[i] == '0')
        ++i;

      groups.push_back({start, i - start});
      int index = groups.size() - 1;

      for (int j = start; j < i; ++j)
        groupIndex[j] = index;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1')
        groupIndex[i] =
            upper_bound(
                groups.begin(), groups.end(), i,
                [](int position, const Group& group) {
                  return position < group.start;
                }) -
                groups.begin() -
            1;
    }

    if (groups.empty())
      return vector<int>(queries.size(), ones);

    vector<int> merged;

    for (int i = 0; i + 1 < groups.size(); ++i)
      merged.push_back(groups[i].length + groups[i + 1].length);

    SegmentTree segmentTree(merged);
    vector<int> answer;
    answer.reserve(queries.size());

    for (const auto& query : queries) {
      int leftPosition = query[0];
      int rightPosition = query[1];

      int leftGroup = groupIndex[leftPosition];
      int rightGroup = groupIndex[rightPosition];

      int leftPart = -1;
      int rightPart = -1;

      if (s[leftPosition] == '0')
        leftPart =
            groups[leftGroup].start + groups[leftGroup].length - leftPosition;

      if (s[rightPosition] == '0')
        rightPart = rightPosition - groups[rightGroup].start + 1;

      int firstCompleteGroup = leftGroup + 1;
      int lastCompleteGroup =
          s[rightPosition] == '1' ? rightGroup : rightGroup - 1;

      int best = ones;

      if (s[leftPosition] == '0' && s[rightPosition] == '0' &&
          leftGroup + 1 == rightGroup) {
        best = max(best, ones + leftPart + rightPart);
      } else if (firstCompleteGroup < lastCompleteGroup) {
        best = max(
            best,
            ones + segmentTree.query(firstCompleteGroup, lastCompleteGroup - 1));
      }

      if (s[leftPosition] == '0' &&
          leftGroup + 1 <= lastCompleteGroup) {
        best = max(
            best,
            ones + leftPart + groups[leftGroup + 1].length);
      }

      if (s[rightPosition] == '0' && leftGroup < rightGroup - 1) {
        best = max(
            best,
            ones + rightPart + groups[rightGroup - 1].length);
      }

      answer.push_back(best);
    }

    return answer;
  }
};