#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    if(n%2==0)
    {
        cout << -1 << endl;
        return;
    }

    for(int i=n;i>=1;i=i-2)
    {
        cout << i << " ";
    }
    for(int i=2;i<=n-1;i=i+2)
    {
        cout << i << " ";
    }

    cout << endl;
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