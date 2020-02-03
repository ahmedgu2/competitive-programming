#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[100005];
    int coinChange(vector<int>& coins, int amount) {
        for(int s = 1; s <= amount; s++){
            dp[s] = 1e8;
            for(int i = 0; i < coins.size(); i++){
                if(s >= coins[i])
                    dp[s] = min(dp[s], 1 + dp[s-coins[i]]);
            }
        }
        return (dp[amount] == 1e8 ? -1 : dp[amount]);
    }
};