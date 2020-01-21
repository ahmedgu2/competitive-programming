#include<bits/stdc++.h>
using namespace std;


// O(N*N) Solution
class Solution {
public:
    
    unordered_map<char, bool> found;
    
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int ans = 1, cur = 1;
        int n = s.length();
        for(int l = 0; l < n; l++){
            found.clear();
            found[s[l]] = true;
            cur = 1;
            for(int r = l+1; r < n; r++){
                if(found.find(s[r]) != found.end())
                    break;
                cur++;
                ans = max(ans, cur);
                found[s[r]] = true;
            }
        }
        return ans;
    }
};