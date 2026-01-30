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
   int n;cin>>n;
   string s; cin>>s;

   string t = s;

   int ct = 0;
   int studs = 0;

   for(int i=0;i<n;i++)
   {
        if(s[i]=='1')
        {
            ++studs;
            if(i+1<n) t[i+1]='1';
            if(i-1>=0) t[i-1]='1';
        }
   }

   for(int i=0;i<n;i++)
   {
        if(t[i]=='1') continue;
        int ptr = i;
        int loc = 0;
        while(ptr<n&&t[ptr]=='0')
        {
            ++ptr;
            ++loc;
        }
        i=ptr-1;
        studs += (loc+2)/3;
   }

   cout << studs << "\n";
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