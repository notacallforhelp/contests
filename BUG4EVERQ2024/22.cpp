#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n; cin>>n;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    ll gscore = 0;
    ll mscore = 0;
    ll turn = 1;

    ll l = 0;
    ll r = n-1;

    while(l<=r)
    {
        ll elechosen = max(A[l],A[r]);
        if(turn%2!=0)
        {
            mscore += elechosen;
            if(elechosen==A[l])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        else
        {
            gscore += elechosen;
            if(elechosen==A[l])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        ++turn;
    }

    gscore >= mscore ? cout << "1\n" : cout << "0\n";
}   


int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}