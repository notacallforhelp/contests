#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ++count;
        }
    }
    if(count&1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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