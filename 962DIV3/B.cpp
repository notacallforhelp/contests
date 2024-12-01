#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin>>n>>k;

    char p;

    int A[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>p;
            A[i][j]=(int)p-48;
        }
    }

    if(k==1)
    {
        
    }


    for(int i=0;i<n;i=i+k)
    {
        for(int j=0;j<n;j=j+k)
        {
            cout << A[i][j];
        }

        cout << endl;
    }

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