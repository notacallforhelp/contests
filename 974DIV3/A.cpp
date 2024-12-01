#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    ll n, k; cin>>n>>k;

    vector<ll> A(n);

    ll gold = 0;

    ll output = 0;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(A[i]>=k) gold += A[i];
        if(A[i]==0)
        {
            if(gold>0)
            {
                --gold;
                ++output;
                //cout << i << " ";
            }
        }
    }
    //cout << endl;

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