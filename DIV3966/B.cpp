#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    map<int,bool> M;

    for(int i=1;i<=n;i++)
    {
        M[i]=0;
    }

    M[A[0]]=1;

    for(int i=1;i<n;i++)
    {
        int seat = A[i];

        if(seat==1)
        {
            if(M[seat+1]==0)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                continue;
            }
        }

        if(seat==n)
        {
            if(M[seat-1]==0)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                continue;
            }
        }

        if(M[seat-1]==0&&M[seat+1]==0)
        {
            cout << "NO\n";
            return;
        }

        M[seat]=1;
    }

    cout << "YES\n";
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