#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   string x; cin>>x;

   if(n%2!=0)
   {
        if(x[0]=='b')
        {
            cout << "NO\n"; return;
        }
   }
   else
   {
        if(x[0]==x[1])
        {
            cout << "NO\n"; return;
        }
   }

   int score = 0;

   for(int i=0;i<n;i++)
   {
        if(x[i]=='?')
        {
            if(i==0)
            {
                if(n%2!=0)
                {
                    x[i]='a';
                }
                else
                {
                    
                }
            }
            if(score==1) x[i]='b';
            if(score==-1) x[i]='a';
            if(score==0)
            {
                if(i+1<n)
                {
                    if(x[i-1]==x[i+1])
                    {
                        if(x[i-1]=='b') x[i]='a';
                        if(x[i-1]=='a') x[i]='b';
                    }
                    else
                    {
                        x[i]=x[i-1];
                    }
                }
                else
                {
                    x[i]=x[i-1];
                }
            }
        }
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