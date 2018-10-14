#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int gap = 99999;
        int result;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size && j != i; j++) {
                for (int k = 0; k < size && k != i && k != j; k++) {
                    int temp = nums[i] + nums[j] + nums[k];
                    int curGap = abs(temp - target);
                    if (curGap < gap) {
                        gap = curGap;
                        result = temp;
                    }
                }
            }
        }
        return result;
    }
};


class Solution2 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int gap = 99999;
        int result;
        
        vector<int> sums; // sum of two number except self
        for (int i = 0; i < size; i++) {
            sums.push_back(target - nums[i]);
        }

        sort(sums.begin(), sums.end());
        int min = sums[0];
        int split;
        if (min < 0) {
            for (int i = 0; i < size; i++) {
                sums[i] += (-min);
            }
        }

        



    }
};



