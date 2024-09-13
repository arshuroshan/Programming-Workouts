#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    stack.push(c);
                    break;
                case ')':
                    if (stack.empty() || stack.top() != '(') {
                        return false;
                    }
                    stack.pop();
                    break;
                case ']':
                    if (stack.empty() || stack.top() != '[') {
                        return false;
                    }
                    stack.pop();
                    break;
                case '}':
                    if (stack.empty() || stack.top() != '{') {
                        return false;
                    }
                    stack.pop();
                    break;
                default:
                    return false; // Invalid character
            }
        }

        return stack.empty();
    }
};