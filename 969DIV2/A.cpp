#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r;
    cin>>l>>r;
    
    if(l&1) --l;
    if(r&1) ++r;

    cout << (r-l)/4 << endl;
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