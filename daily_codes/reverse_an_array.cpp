//This is a code to reverse an array using recursion

#include<bits/stdc++.h>
using namespace std;

void reverseArray(int *l,int *r){
    if(l>=r) return;
    int temp = *l;
    *l = *r;
    *r = temp;
    reverseArray(l+1,r-1);
}

int main(void){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int *first = &arr[0];
    int *last = &arr[n-1];
    reverseArray(first,last);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}
