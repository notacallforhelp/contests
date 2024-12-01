#include <bits/stdc++.h>


using namespace std;

typedef long long int ll;

void solve()
{
    ll n;cin>>n;

    ll x, y;
    cin>>x>>y;

    if(x<y)
    {
        ll output = n/x;
        if(n%x!=0)
        {
            ++output;
        }

        cout << output<<endl;
    }
    else
    {
        ll output = n/y;
        if(n%y!=0)
        {
            ++output;
        }

        cout << output << endl;
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