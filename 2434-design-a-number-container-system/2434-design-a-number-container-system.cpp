#include <unordered_map>
#include <queue>
#include <utility>

class NumberContainers {
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }

        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        if (numberToIndices.count(number)) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }

private:
    std::unordered_map<int, int> indexToNumber;
    std::unordered_map<int, std::set<int>> numberToIndices;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */