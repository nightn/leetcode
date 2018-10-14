#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "999-utils.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> myMap;
        for (int i = 0; i < size; i++) {
            myMap[nums[i]] = i;
        }
        // printMap(myMap);
        int i, j = -1;
        for (i = 0; i < size; i++) {
            int other = target - nums[i];
            auto it = myMap.find(other);
            // 注意, it 指向的是一个 pair 对象
            if (it != myMap.end() && it->second != i) {
                j = it->second;
                return vector<int>{i, j};
            }
        }
        return vector<int>();
    }
};

int main() {
    Solution sln;
    vector<int> nums = {2, 7, 11, 15};
    nums = {3, 2, 4};
    int target = 6;
    vector<int> res = sln.twoSum(nums, target);
    printContainer(res);
}

