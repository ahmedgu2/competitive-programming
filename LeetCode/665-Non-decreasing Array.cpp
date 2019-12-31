#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ret = 0;
        for(int i = 1; i < nums.size() && ret <= 1; i++){
            if(nums[i] < nums[i-1]){
                ret++;
                if(i-2 < 0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return ret <= 1;
    }
};

