//Given an array arr of N integers. Given Q queries and in each query given a number x,print count of that number in array
//Constraints - 
// 1<=N<=10^5
// 1<=arr[i]<=10^7
// 1<=Q<=10^5

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
int hsh[N]; //Creating a hash array to pre-compute the count of each value

int main(void){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
        hsh[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<hsh[x]<<"\n";
    }
    return 0;
}
