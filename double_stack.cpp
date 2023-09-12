#include "bits/stdc++.h"

using namespace std;

void cal(stack<int> &nums, stack<char> &ops) {
    auto op = ops.top();
    ops.pop();
    auto n2 = nums.top();
    nums.pop();
    auto n1 = nums.top();
    nums.pop();

    int ans;
    switch (op) {
        case '+':
            ans = n1 + n2;
            break;
        case '-':
            ans = n1 - n2;
            break;
        case '*':
            ans = n1 * n2;
            break;
        case '/':
            ans = n1 / n2;
        default:
            ans = (int)pow(n1, n2);
    }
    nums.push(ans);
}

int evaluate(string s) {
    s = regex_replace(s, regex("\\s+"), "");
    s = regex_replace(s, regex("\\(-"), "(0-");
    s = regex_replace(s, regex("\\(\\+"), "(");

    stack<int> nums;
    stack<char> ops;
    nums.push(0);
    map<char, int> orders{
            {'+', 0},
            {'-', 0},
            {'*', 1},
            {'/', 1},
            {'^', 2}
    };

    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            int ans = 0;
            while (i < s.size() && isdigit(s[i])) {
                ans = ans * 10 + (s[i] - '0');
                i++;
            }
            i--;
            nums.push(ans);
        }

        else if (orders.contains(s[i])) {
            while (!ops.empty() && orders.contains(ops.top()) && orders[ops.top()] >= orders[s[i]]) {
                cal(nums, ops);
            }
            ops.push(s[i]);
        }

        else if (s[i] == '(') {
            ops.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                cal(nums, ops);
            }
            ops.pop();
        }

        else {
            throw invalid_argument(&"unrecognized token "[s[i]]);
        }
    }

    while (!ops.empty()) {
        cal(nums, ops);
    }

    return nums.top();
}

int main() {
    string s = "4 * (2 + 3) + 1 * 2";
    cout << evaluate(s) << endl;
}
