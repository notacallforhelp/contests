#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define int long long
typedef long long ll;
typedef long double ld;

//struct for range 
struct range
{
    int l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

void solve()
{   
   int n; cin>>n;
   string s; cin>>s;
   vector<int> ones;
   vector<int> zeroes;

   for(int i=0;i<n;i++)
   {
        if(s[i]=='1') ones.push_back(i);
        if(s[i]=='0') zeroes.push_back(i);
   }

   int k = zeroes.size();
   int other = n-k;

   if(k%2==1)
   {
        vector<int> ans;
        int ptr0=0;
        for(int i=0;i<k;i++)
        {
                ans.push_back(zeroes[ptr0]);
                ++ptr0;
        }

        cout << ans.size() << "\n";
        for(auto &ele:ans)
        {
            cout << ele +1 << " ";
        }
        if(ans.size()>=1) cout << "\n";
   }
   else if(other%2==0)
   {
        vector<int> ans;
        int ptr1=0;
        for(int i=0;i<other;i++)
        {
            ans.push_back(ones[ptr1]);
            ++ptr1;
        }

        cout << ans.size() << "\n";
        for(auto &ele:ans)
        {
            cout << ele +1 << " ";
        }
        if(ans.size()>=1) cout << "\n";
   }
   else
   {
        cout << "-1\n";
   }
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