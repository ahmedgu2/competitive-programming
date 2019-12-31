#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        
        int tmp[27], occB[27], occA[27];
        
        memset(tmp, 0, sizeof tmp);
        memset(occB, 0, sizeof occB);
        memset(occA, 0, sizeof occB);
        
        for(auto &w : B){
            memset(tmp, 0, sizeof tmp);
            for(int i = 0; i < w.length(); i++)
                tmp[w[i] - 'a']++;
            for(int i = 0; i < 27; i++)
                occB[i] = max(occB[i], tmp[i]);
        }
                
        vector<string> ans;

        for(auto &w : A){
            memset(occA, 0, sizeof occA);
            for(int i = 0; i < w.length(); i++)
                occA[w[i] - 'a']++;
            
            cout << w << endl;
            bool is_univ = true;
            for(int i = 0; i < 27; i++){
                if(occA[i] < occB[i]){
                    is_univ = false;
                    break;
                }
            }

            if(is_univ)
                ans.push_back(w);
        }
        
        return ans;
    }
};
