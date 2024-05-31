//A code to determine if a string is palindrome or not using recursive function calls

#include <bits/stdc++.h>
using namespace std;

bool palindrome(const string str,int i,int j){
    if(i>=j) return true;
    if(str[i]!=str[j]) return false;
    palindrome(str,i+1,j-1);
}

int main(void) {
    string str;
    getline(cin,str);
    if(palindrome(str,0,str.length()-1)) cout<<"The string is a palindrome"; 
    else cout<<"The string is not a palindrome string";
    return 0;
}
