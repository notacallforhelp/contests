#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;
    cin>>x>>y;
    if(x==0&&y==0)
    {
         cout << 0 << endl;
         return;
    }
    int ans = 0;
    
    ans = y/2;
    if(x-(y/2)*7>=0)
    {
        x=x-(y/2)*7;
    }
    else
    {
        x=0;
    }
    if(y%2)
    {
        ++ans;
        if(x-11>=0)
        {
            x=x-11;
        }
        else
        {
            x=0;
        }
    }

    ans += (x/15);
    if(x%15!=0)
    {
        ++ans;
    }
    if(ans==0) cout << 1 << endl;
    else cout << ans << endl;
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