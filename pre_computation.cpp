#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long fact[N];

int main(void){
    //we will pre compute the factorial values and use it later inside the while loop
    //this way we didnt have to use two loops and the time complexity has been reduced
    fact[0] = fact[1] = 1; 
    for(int i=2;i<N;++i){
        fact[i] = fact[i-1]*i;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fact[n]<<"\n";
    }
    return 0;
}