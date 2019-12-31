#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        //first approach : check if log2(n) is int using ceil and floor.
        //return (ceil(log2(n)) == floor(log2(n)));
        
        //second approach : get the number of 1's in the binary rep. of the number 
        //if n is power of 2, it must have only one 1 in it's binary rep.
        int cnt = 0;
        while(n){
            cnt += (n & 1);
            if(cnt > 1)
                return false;
            n >>= 1;
        }
        return true;
    }
};