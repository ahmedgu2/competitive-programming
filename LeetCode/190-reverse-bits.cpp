#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 1;
        for(int i = 0; i < 32; i++){
            ans = ans*2 + n%2;
            n /= 2;
        }
        return ans;
    }
};