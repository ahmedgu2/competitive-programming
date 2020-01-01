#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findJudge(int N, vector<vector<int>>& trust) {
        int in[N+1], out[N+1];
        
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        

        for(auto &edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
        int judge = -1;
        for(int i = 1; i <= N; i++){
            if(out[i] == 0 && in[i] == N-1){
                if(judge != -1)
                    return -1;
                judge = i;
            }
        }
        return judge;
    }
};