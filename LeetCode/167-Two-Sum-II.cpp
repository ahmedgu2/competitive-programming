#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

class Solution {
public:
    
    gp_hash_table<int, int> m;
    vector<int> ans;
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        //using hash table
        /*for(int i = 0; i < numbers.size(); i++){
            if(m.find(target-numbers[i]) != m.end()){
                ans.push_back(m[target-numbers[i]]+1);
                ans.push_back(i+1);
                return ans;
            }
            m[numbers[i]] = i;
        }*/
        
        int i = 0, j = numbers.size()-1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            if(sum > target)
                j--;
            else
                i++;
        }
        return ans;
    }
};