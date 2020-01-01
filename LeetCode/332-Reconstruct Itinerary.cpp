#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    map<string, multiset<string> > adj;
    map<string, map<string, int> > vis;
    vector<string> ans;
    int root;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto &edge : tickets)
            adj[edge[0]].insert(edge[1]);
        
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    //find euler path (directed graph) Hierholzer’s Algorithm
    void dfs(string u) {
       while(adj[u].size()){
           string v = *adj[u].begin();
           adj[u].erase(adj[u].begin());
           dfs(v);
       }
        ans.push_back(u);
    }
};