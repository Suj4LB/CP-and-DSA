// A simple c++ program to find repeating element in an array in O(n) running time complexity

#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;++i){
        cin>>arr[i];        
    }
    
    int sum = 0;      
    
    for(int i=0;i<n;++i){
        sum = sum+arr[i];
    }
    
    int sum_check = (n*(n-1))/2;
    cout<<sum_check - sum;

    return 0;
}

