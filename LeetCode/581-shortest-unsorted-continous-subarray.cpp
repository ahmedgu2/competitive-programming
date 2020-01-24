#include<bits/stdc++.h>
using namespace std;

//O(N*logN) Solution
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto tmp = nums;
        sort(tmp.begin(), tmp.end());
        int low = -1;
        int high = -2;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] == tmp[i])
                continue;
            if(low == -1)
                low = i;
            else
                high = i;
        }
        return high - low + 1;
    }
};

//O(N) Solution
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int l = -1, r = -2;
        int p_max = INT_MIN, s_min = INT_MAX;
        for(int i = 0; i < n; i++){
            j = n - 1 - i;
            p_max = max(p_max, nums[i]);
            s_min = min(s_min, nums[j]);
            if(nums[i] < p_max)
                r = i;
            if(nums[j] > s_min)
                l = j;
        }
        return r - l + 1;
    }
};