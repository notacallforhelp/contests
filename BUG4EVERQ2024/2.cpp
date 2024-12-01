#include <bits/stdc++.h>

using namespace std;

int A[100];

int fn(int pos,int n,int turns)
{
    if(turns>(n/2+n%2)) return 0;
    return max(A[pos]+fn(pos+1,n,turns+1),A[n-pos-1]+fn(pos+1,n,turns+1));
}

void solve()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int mscore = 0;

    int turns = n/2+n%2;
    int pos=0;

    cout <<fn(pos,n,1)<<endl;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}