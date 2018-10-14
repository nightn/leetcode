#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> result;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size && j != i; j++) {
                for (int s = 0; s < size && s != i && s != j; s++) {
                    for (int t = 0; t < size && t != i && t != j && t != s; t++) {
                        if (nums[i] + nums[j] + nums[s] + nums[t] == target) {
                            result = { nums[i], nums[j], nums[s], nums[t] };
                            sort(result.begin(), result.end());

                            if(find(results.begin(), results.end(), result) == results.end()) {
                                results.push_back(result);
                            }
                        }
                    }
                }
            }
        }
        return results;
    }
};

