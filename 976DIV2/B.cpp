#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    ll k; cin>>k;

    ll cnt_pfsq =0;
    ll i=1;

    /*while(i*i<=k)
    {
        ++cnt_pfsq;
        ++i;
    }*/
    cnt_pfsq = sqrt(k);

    /*
    //cout << cnt_pfsq << endl;
    while(cnt_pfsq)
    {
        ++k;
        if(k>1000000000)
        {
            break;
        }
        ll m = sqrt(k);
        if((m*m)!=k)
        {
            --cnt_pfsq;
        }
    }
    cout << k+cnt_pfsq << endl;*/
    k=k+cnt_pfsq;

    ll hmm = sqrt(k);
    ll output = k+(hmm-cnt_pfsq);
    cout << output << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}