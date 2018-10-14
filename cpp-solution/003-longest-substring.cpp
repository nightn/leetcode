#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// longest substring without repeating characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        set<char> charSet;
        int i = 0, j = 0;
        int n = s.size();
        // sliding window
        while (i < n && j < n) {
            // not found
            if (charSet.find(s[j]) == charSet.end()) {
                charSet.insert(s[j++]);
                maxLen = max(maxLen, j - i);
            } else {
                charSet.erase(s[i++]);
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sln;
    string s1("pwwkew");
    cout << sln.lengthOfLongestSubstring(s1) << endl;


}
