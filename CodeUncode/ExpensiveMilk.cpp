#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, z;
    cin>>x>>y>>z;
    if(x>=y*z)
    {
        cout << "Mazze\n";
    }
    else
    {
        cout<< "Dudh Mehenga Hai\n";
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