#include "bits/stdc++.h"

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int maxLen = 0, left = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (m.contains(s[i])) {
            // typical hard problem for logical deduction
            // prove m[s[i]] will not always greater or equal to left
            left = max(left, m[s[i]] + 1);
        }
        m[s[i]] = i;
        maxLen = max(maxLen, i - left + 1);
    }
    return maxLen;
}

int main() {
    string s = "abcdcefg";
    int result = lengthOfLongestSubstring(s);
    printf("%d\n", result);
    return 0;
}