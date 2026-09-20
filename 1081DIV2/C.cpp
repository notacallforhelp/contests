#include <bits/stdc++.h>
using namespace std;


#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n,h,k; cin>>n>>h>>k;
   vector<int> A(n+1),pf(n+1),mnpf(n+1,1e17);
   for(int i=1;i<=n;i++)
   {
        cin>>A[i];
   }
   for(int i=1;i<=n;i++)
   {
        pf[i]=pf[i-1]+A[i];
        mnpf[i]=min(mnpf[i-1],A[i]);
   }

   vector<int> mxsf(n+2,0);
   for(int i=n;i>=1;i--)
   {
        mxsf[i]=max(mxsf[i+1],A[i]);
   }

   int mult = h/pf[n];
   int output = mult*n + max(mult-1,0ll)*k;
   int left = h - mult*pf[n];
   if(left==0)
   {
        cout << output << "\n";
        return;
   }

   if(mult>=1) output += k;

   mnpf[0]=0;

   for(int i=1;i<=n;i++)
   {

        int mxdmg = max(pf[i],pf[i]-mnpf[i]+mxsf[i+1]);
        if(mxdmg>=left)
        {
            output+=i;
            break;
        }
   }

   cout << output << '\n';


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}