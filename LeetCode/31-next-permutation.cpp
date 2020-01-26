#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
       
        If we consider the elements of the array as a number (i.e : the number x = 1234651), then searching for the next
        permutation means that we need to get the minimum number that is bigger that x (this number being 1235146).
        If we know this, we can notice that when having a number where its digits are sorted in descending way, 
        that number is considered as the last permutation of its digits, meaning we can't permute its digits to get any larger
        number from it as in this form, it's the largest number possible.
        Example : 
        A = [1, 2, 4, 6, 5, 1]
        The decreseasing seq A[3:5] can't be permuted to get the next permutation as it is sorted in a decreasing way,
        thus swapping any pair of items int that sequence will cause the number to get smaller and thus getting back to a previous permutation.
        The idea is to introduce the digit that comes before the first digit of that sequence and figure out a way to
        make the number as small as possible while being larger than the last one. This can be done by applying the 
        algorithms mentioned below :
        
        1-Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done. 
        2-Find the largest index l > k such that nums[k] < nums[l].
        3-Swap nums[k] and nums[l].
        4-Reverse the sub-array nums[k + 1:].  

        */
        
        int n = nums.size();
        if(n == 1)
            return;
        bool flag = false;
        int low = -1;
        
        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1])
                low = i;
            
        }
        if(low == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int high = low;
        for(int i = low+1; i < n; i++){
            if(nums[low] < nums[i])
                high = i;
        }

        /* We can use binary search to get find the largest index l > k such that nums[k] < nums[l] since
        we know that the sequence [k+1:l] is sorted. We just need to search for the upper bound
        of nums[low] in that sequence (the smallest number bigger than nums[low]).
        int high = low;
        auto it = lower_bound(nums.begin() + low + 1, nums.end(), nums[low], greater<int>());
        high = it - nums.begin() - 1;
        */

        swap(nums[low], nums[high]);
        reverse(nums.begin() + low + 1, nums.end());
    }
};