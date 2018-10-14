#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;  // special case
        string result;
        int maxDet = (numRows - 1) * 2;
        int size = s.size();
        for (int i = 0; i < numRows; i++) {
            int j = 0;
            // 第一行和最后一行的 det 是固定的，即 maxDet
            if (i == 0 || i == numRows - 1) {
                while (i + j * maxDet < size) {
                    result.push_back(s[i + j * maxDet]);
                    ++j;
                }
            }
            // 中间的行，det 在 oodDet 和 evenDet 间不断切换
            else {
                int evenDet = (numRows - i - 1) * 2; 
                int oddDet = i * 2;
                int curDet = evenDet;
                int curIndex = i - curDet;
                while ((curIndex += curDet) < size) {
                    result.push_back(s[curIndex]);
                    curDet = (j % 2 ? oddDet : evenDet);
                    ++j;
                }
            }
        }
        return result;
    }
};


int main() {
    Solution sln;
    string s1 = "PAYPALISHIRING";
    cout << sln.convert(s1, 3) << endl;
    cout << sln.convert(s1, 4) << endl;
    
}


// PAYPALISHIRING

// P   A   H   N
// A P L S I I G
// Y   I   R

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// P       H
// A     S I
// Y   I   R
// P L     I G
// A       N
