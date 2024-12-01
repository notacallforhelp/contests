#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

void solve()
{
    int n;
    cin >> n;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    for(int i=1;i<=n-2;i++)
    {
        if(A[i-1]>0)
        {
            while(A[i-1]>0)
            {
                A[i-1]=A[i-1]-1;
                A[i]=A[i]-2;
                A[i+1]=A[i+1]-1;
            }

        }
    }

    for(int i=0;i<n;i++)
    {
        if(A[i]!=0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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