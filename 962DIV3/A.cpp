#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int output = n/4;

    if(n%4!=0)
    {
        ++output;
    }

    cout << output << endl;
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