#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    sort(A.begin(),A.end());

    int global = 0;
    int local = 0;
    int current = A[0];

    for(int i=0;i<n;i++)
    {
        if(A[i]-current<=1)
        {
            ++local;
            current = max(current,A[i]);
        }
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