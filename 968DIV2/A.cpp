#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    if(s[0]==s[s.length()-1])
    {
        cout << "no\n";
    }
    else
    {
        cout << "yes\n";
    }
    
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}