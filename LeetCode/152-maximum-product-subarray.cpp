#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], imax = 1, imin = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)
                swap(imax, imin);
            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);
            ans = max(ans, imax);
        }
        return ans;
    }
};