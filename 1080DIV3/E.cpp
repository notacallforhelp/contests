#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int mod = 1e9+7;
const int N = 3e5+10;

vector<int> adj[N];
vector<int> dp(N);

int dfs(int v,int p)
{
    if(adj[v].size()==1)
    {
        return dp[v]=0;
    }

    int val = 4;
    for(auto &child:adj[v])
    {
        if(child!=p)
        {
           val = (val+ dfs(child,v))%mod;
        }
    }

    return dp[v] = val;
}

void dfs2(int v,int p)
{
    for(auto &child:adj[v])
    {
        if(child!=p)
        {
            dp[child] = (dp[child]+dp[v] +1)%mod;
            dfs2(child,v);
        }
    }
    return;
}

void solve()
{   
   int n; cin>>n;

   adj[0].push_back(1);
   adj[1].push_back(0);
   dp[0]=0;

   for(int i=1;i<=n;i++)
   {
        dp[i]=0;
        int l,r; cin>>l>>r;
        if(l==0&&r==0) continue;
        adj[i].push_back(l); adj[l].push_back(i);
        adj[i].push_back(r); adj[r].push_back(i);
   }

   dfs(1,0);

//    for(int i=1;i<=n;i++)
//    {
//         cout << dp[i] << " " ;
//    }
//    cout << "\n";

   dfs2(0,-1);

   for(int i=1;i<=n;i++)
   {
        cout << dp[i] << " " ;
   }
   cout << "\n";

   for(int i=0;i<=n;i++)
   {
        dp[i]=0;
        adj[i].clear();
   }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}