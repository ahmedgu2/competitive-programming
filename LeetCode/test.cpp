#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v = {1,2,3,4};
    int n = 4;
    for(int j = 0; j <= 1<<n; j++){
        cout << "{ ";
        for(int i = 0; i < n; i++){
            if((j>>i) & 1)
                cout << v[i] << " ";
        }
        cout << " }" << endl;
    }
    return 0;
}