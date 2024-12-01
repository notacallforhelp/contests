#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,c,d;
    cin>>n>>c>>d;

    vector<int> A(n*n);
    map<int,int> M;
    for(int i=0;i<n*n;i++)
    {
        cin>>A[i];
        ++M[A[i]];
    }
    
    sort(A.begin(),A.end());
    int begin=A[0];
    int B[n][n];
    B[0][0]=begin;
    for(int i=1;i<n;i++)
    {
        B[0][i]=B[0][i-1]+d;
    }
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<n;i++)
        {
            B[i][j]=B[i-1][j]+c;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[B[i][j]]==0)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                --M[B[i][j]];
            }
        }
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