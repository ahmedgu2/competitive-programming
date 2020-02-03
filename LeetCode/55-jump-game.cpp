#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool canJump(vector<int>& nums) {
        int r = 0;
        for(int i = 0; i < nums.size(); i++){
            if(r < i)
                break;
            r = max(r, i + nums[i]);
        }
        return r >= (nums.size() - 1);
    }
};