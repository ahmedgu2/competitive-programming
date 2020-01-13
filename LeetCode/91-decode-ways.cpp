#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dp[100005];
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return ways(s, 0, s.length());
    }
    
    int ways(string s, int i, int n){
        if(i >= n)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = 0;
        if(s[i] > '0')
            dp[i] += ways(s, i+1, n);
        if(i+2 <= n  && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
            dp[i] += ways(s, i+2, n);
        
        return dp[i];
    }
};