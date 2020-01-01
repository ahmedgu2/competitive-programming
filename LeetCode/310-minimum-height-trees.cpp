#include<bits/stdc++.h>
using namespace std;

/**
 * min height trees have roots as the mid node (or two mid nodes) in the longest path in the tree.
 * 
*/

class Solution {
public:
    
    vector< vector<int> > adj;
    vector<int> path;
    vector<int> ans;
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        adj.resize(n+1);
        
        //convert edges to adj list
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        //get the longest path in tree(p -> p2)
        auto p = bfs(0, n);
        auto p2 = bfs(p.first, n);
        //get mid point in path
        dfs(p.first, -1, p2.first);
        return ans;
        
    }
    
    pair<int, int> bfs(int s, int n){
        
            queue<int> q;
            bool vis[n+1];
            int dist[n+1];
            memset(dist, 0, sizeof dist);
            memset(vis, false, sizeof vis); 
            q.push(s);
            vis[s] = true;
        
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]){
                    if(vis[v])
                        continue;
                    vis[v] = true;
                    dist[v] = dist[u] + 1;  
                    q.push(v);
                }
            }
            
            int f = 0;
            int maxx = dist[0];
            for(int i = 1; i < n; i++){
                if(dist[i] > maxx){
                    f = i;
                    maxx = dist[i];
                }
            }
            return make_pair(f, maxx);
        }
    
    void dfs(int u, int parent, int to){
        
        path.push_back(u); 
        if(u == to){
        
            int n = path.size();
            //if len(path) is even => 2 mid points
            if(n % 2 == 0){
                ans.push_back(path[n/2]);
                ans.push_back(path[n/2-1]);
            }else{
                ans.push_back(path[n/2]);
            }
            return;
        }
        
        for(auto &v : adj[u]){
            if(v == parent)
                continue;
            dfs(v, u, to);
            path.pop_back();
        }
    }
    
};