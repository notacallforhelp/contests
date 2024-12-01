#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        if(n<29)
        {
            char c = n-3+'a';
            cout << "aa" << c << endl;
        }
        else if(n<54)
        {
            char c = n-28+'a';
            cout << "a"<<c << "z\n";
        }
        else
        {
            char c = n-53+'a';
            cout << c << "zz\n";
        }
    }
}