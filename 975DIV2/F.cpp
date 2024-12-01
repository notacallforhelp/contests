#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    int n; cin>>n;
    vector<ll> A(n);

    ll mxodd=0; ll mnodd=1e10;
    ll mxeve=0; ll mneve=1e10;
    ll mxpos=-1;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(i%2==0)
        {
            mxeve = max(mxeve,A[i]);
            mneve = min(mneve,A[i]);
        }
        else
        {
            mxodd = max(mxodd,A[i]);
            mnodd = min(mnodd,A[i]);
        }
    }
    cout << max((mxeve+mneve+n%2+n/2),(mxodd+mnodd+n/2))<<endl;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}