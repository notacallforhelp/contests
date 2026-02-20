#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef long long ll;
typedef long double ld;

int get_bit_count(long long n){
	return __builtin_popcountll(n);
}

void solve()
{   
   int n; cin>>n;

   int k = get_bit_count(n);

   if(k==1)
   {
        cout << -1 << "\n"; return;
   }

   vector<int> P(n+1);

   P[n]=1;

   for(int i=n-1;i>=2;i--)
   {
        if(i%2==0)
        {
            P[i]=i+1;
        }
        else
        {
            P[i]=i-1;
        }
   }

   if(n%2==0)
   {
        P[1]=n;
   }
   else
   {
        P[1]=n-1;
   }

   if(n%2==0)
   {
        for(int bit=0;bit<=32;bit++)
        {
            if((1ll<<bit)&n)
            {
                int num = (1ll<<bit);
                swap(P[num],P[1]);
                break;
            }
        }
   }

   for(int i=1;i<=n;i++)
   {
        cout << P[i] << " ";
   }
   cout << "\n";
   
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