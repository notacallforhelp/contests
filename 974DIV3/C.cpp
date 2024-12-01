#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    ll n; cin>>n;

    vector<ll> A(n);

    ll sum = 0;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        sum += A[i];
    }
    sort(A.begin(),A.end());

    ll mid = A[n/2];

    ll req = mid*n*2 - sum;
    if(n==1||n==2)
    {
        cout << -1 << endl;
        return;
    }

    if(req<0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << req+1 << endl;
    }
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}