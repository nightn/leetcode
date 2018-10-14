#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    static void printRect(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC, vector<int>& v) {
        if (tR == dR) { // 同一行
            for (int i = tC; i <= dC; i++) {
                v.push_back(matrix[tR][i]);
            }
            return;
        }
        if (tC == dC) {
            for (int i = tR; i <= dR; i++) {
                v.push_back(matrix[i][tC]);
            }
            return;
        }
        for (int i = tC; i < dC; i++) {
            v.push_back(matrix[tR][i]);
        }
        for (int i = tR; i < dR; i++) {
            v.push_back(matrix[i][dC]);
        }
        for (int i = dC; i > tC; i--) {
            v.push_back(matrix[dR][i]);
        }
        for (int i = dR; i > tR; i--) {
            v.push_back(matrix[i][tC]);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.size() == 0) {
            return v;
        }
        int tR = 0, tC = 0, dR = matrix.size() - 1, dC = matrix[0].size() - 1;
        while (tR <= dR && tC <= dC) {
            printRect(matrix, tR++, tC++, dR--, dC--, v);
        }
        return v;
    }

};

