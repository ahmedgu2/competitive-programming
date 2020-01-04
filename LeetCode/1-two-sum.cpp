#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

class Solution {
public:
    
    //hash table (faster than unordered_map)
    gp_hash_table<int, int> m;
    vector<int> ans;
    
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++){
            int comp = target-nums[i];
            auto it = m.find(comp);
            if(it != m.end() && it->second != i){
                ans.push_back(m[comp]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};