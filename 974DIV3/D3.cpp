#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, d, k; cin>>n>>d>>k;

    vector<int> start(n+1),end(n+1);

    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        ++start[a];
        ++end[b];
    }

    for(int i=0;i<n;i++)
    {
        start[i+1] += start[i];
        end[i+1] += end[i];
    }

    int mx = 0;
    int brother = 0;
    int mn = 1e9;
    int mom = 0;

    for(int i=d;i<=n;i++)
    {
        int jobs = start[i]-end[i-d];
        if(jobs<mn)
        {
            mn = jobs;
            mom = i-d+1;
        }
        if(jobs>mx)
        {
            mx = jobs;
            brother = i-d+1;
        }
    }

    cout << brother << " " << mom << endl;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}