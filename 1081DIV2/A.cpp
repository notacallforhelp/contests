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
   string s; cin>>s;

   int output = 0;

   for(int rot=0;rot<=n;rot++)
   {
        int loc = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ++loc;
            }
        }
        output=max(output,loc);
        char c = s[n-1];
        for(int i=n-1;i>=0;i--)
        {
            s[i]=s[i-1];
        }
        s[0]=c;
        output=max(output,loc);

        //cout <<s << endl;
   }

   cout << output << "\n";
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