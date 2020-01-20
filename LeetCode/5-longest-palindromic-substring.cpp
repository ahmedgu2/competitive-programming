#include<bits/stdc++.h>
using namespace std;

//Solution 1 : Dynamic programming solution
class Solution {
public:
    
    bool dp[1002][1002];
    
    string longestPalindrome(string s) {
        int n = s.length();
        int best_len = 1;
        int low = 0;
        int len = 0;
        for(int j = 0; j < n; j++){
            for(int i = 0; i <= j; i++){
                len = j - i + 1;
                if(i == j)
                    dp[i][i] = true;
                else if(j == i+1)
                    dp[i][j] = (s[i] == s[j]);                
                else
                    dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));                  
                
                //update best solution of any 
                if(dp[i][j] && best_len < len){
                    best_len = len;
                    low = i;
                } 
            }
        }
        return s.substr(low, best_len);
    }
};

//Solution 2 : expand around center

class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        int best_len = 1;
        int low = 0;
        int len = 0;
        int x = 0;

        //odd
        for(int mid = 0; mid < n; mid++){
            for(x = 0; mid + x < n && mid - x >= 0 ; x++){
                if(s[mid+x] != s[mid-x])
                    break;
                int len = 2*x + 1;
                if(best_len < len){
                    best_len = len;
                    low = mid - x;
                }
            } 
        }
        
        //even
        for(int mid = 0; mid < n-1; mid++){
            for(x = 1; mid + x < n && mid - x + 1 >= 0 ; x++){
                if(s[mid+x] != s[mid-x+1])
                    break;
                int len = 2*x;
                if(best_len < len){
                    best_len = len;
                    low = mid - x + 1;
                }
            }
        }
        return s.substr(low, best_len);
    }
};