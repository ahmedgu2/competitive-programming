#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        map<pair<int, int>, int> m;
        
        for(int i = 0; i < points.size(); i++){
            
            int samePoint = 1;
            int infinite_slope = 0;
            int local_max = 0;
            
            for(int j = i+1; j < points.size(); j++){
                //same point
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    samePoint++;
                else if(points[i][0] == points[j][0]){
                    infinite_slope++;
                }
                else{
                    int diff1 = points[i][1] - points[j][1];
                    int diff2 = points[i][0] - points[j][0];
                    int g = gcd(diff1, diff2);
                    pair<int, int> k = {diff1/g, diff2/g};
                    m[k]++;
                    local_max = max(local_max, m[k]);
                }
                local_max = max(local_max, infinite_slope);
            }
            local_max += samePoint;
            ans = max(ans, local_max);
            m.clear();
        }
        
        return ans;
    }
    
    int gcd(int a, int b){
        return (b == 0 ? a : gcd(b, a%b));
    }
    
};