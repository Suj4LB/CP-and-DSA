// check if a string is palindrome
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string str,str_rev;
        getline(cin, str);
        for (int i = str.size() - 1; i >= 0; i--)
        {
            str_rev.push_back(str[i]);
        }
        if (str == str_rev)
        {
            cout << "It is a palindrome string"<<"\n";
        }
        else
        {
            cout << "It is not a palindrome string"<<"\n";
        }
    }
    return 0;
}