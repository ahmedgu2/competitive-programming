#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length())
            return false;
        
        unordered_map<char, char> cor;
        unordered_map<char, int> occ;
        int n = 0;
        int maxx = 0;
        for(int i = 0; i < A.length(); i++){
            occ[A[i]]++;
            maxx = max(occ[A[i]], maxx);
            if(A[i] != B[i]){
                n++;
                if(n > 2)
                    return false;
                if(n == 1)
                    cor[A[i]] = B[i];
                else{
                    if(cor[B[i]] != A[i])
                        return false;
                }
            }
        }
        if(n == 0){
            if(maxx > 1)
                return true;
            return false;
        }
        return true;
    }
};