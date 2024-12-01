#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n;
    cin>>n;

    vector<ll> A(n+1);

    vector<ll> pf(n+1);
    pf[0]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        pf[i]=pf[i-1]+A[i];
    }
    /*cout << A[2] << " " << A[1] << " " << pf[0] << endl;*/

    cout << A[n]-(A[n-1]-pf[n-2])<<endl;


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