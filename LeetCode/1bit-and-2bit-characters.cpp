#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool is_two = false;
        int n = bits.size()-1;
        for(int i = 0; i <= n; i++){
            if(is_two){
                is_two = false;
                if(i ==  n)
                    return false;
                continue;
            }
            if(bits[i] == 1){
                is_two = true;
            }
        }
        return true;
    }
};