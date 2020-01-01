#include<bits/stdc++.h>
using namespace std;

//Using multiset

 struct compare{
      
    bool operator() (const pair<int, string> a, const pair<int, string> b) const{
        if(a.first == b.first)
            return a.second.compare(b.second) < 0;
        return a.first > b.first;
    }
}; 

class Solution {
public:
    
    map<string, int> occ;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
       
        //1) calculate number of occurances of each word
        for(auto &w : words){
            occ[w]++;
        }
        
        //insert into multiset to be sorted using custom comparator
        multiset< pair<int, string>, compare> ans;
        for(auto &p : occ)
            ans.insert({p.second, p.first});
        
        
        vector<string> ret;
        auto it = ans.begin();
        while(k--){
            ret.push_back(it->second);
            it++;
        }
        return ret;
    }
};

//Using priority_queue

/**
   struct compare{
      
    bool operator() (const pair<int, string> a, const pair<int, string> b) const{
        if(a.first == b.first)
            return a.second.compare(b.second) > 0;
        return a.first < b.first;
    }
}; 

class Solution {
public:
    
    map<string, int> occ;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
       
        //1) calculate number of occurances of each word
        for(auto &w : words){
            occ[w]++;
        }
        
        //insert into priorit_queue to be sorted using custom comparator
        priority_queue< pair<int, string>, std::vector<pair<int, string> >, compare> ans;
        for(auto &p : occ)
            ans.push({p.second, p.first});
        
        
        vector<string> ret;
        while(k--){
            ret.push_back(ans.top().second);
            ans.pop();
        }
        return ret;
    }
};

*/