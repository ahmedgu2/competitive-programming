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

// O(N) Solution
class Solution {
public:
    
    int last_pos[257];
    
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            start = max(last_pos[s[i]], start);
            last_pos[s[i]] = i+1;
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};