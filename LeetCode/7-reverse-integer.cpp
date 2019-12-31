#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x){
            ans = (x%10) + (ans*10);
            x /= 10;
        }
        if(ans > INT_MAX || ans < -INT_MAX)
            return 0;
        return ans;
    }
};