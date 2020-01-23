#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_max = 0, ans = nums[0];
        for(int i = 0; i < nums.size(); i++){
            cur_max = max(nums[i], cur_max + nums[i]);
            ans = max(ans, cur_max);
        }
        return ans;
    }
};