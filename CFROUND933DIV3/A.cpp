#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> A(n);
    vector<int> B(m);
    int ct = 0;

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>> B[i];
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((B[j]+A[i])<=k)
            {
                ++ct;
            }
        }
    }
    cout << ct << endl;
}

int main()
{
    fast;
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}