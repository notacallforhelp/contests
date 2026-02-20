#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   vector<int> A(n);
   for(auto &ele:A) cin>>ele;

   int output = 0;

   for(int i=1;i<n;i++)
   {
        int loc =0;
        int ptr = i;
        while(ptr<n&&(A[ptr]==A[ptr-1]||A[ptr]==7-A[ptr-1]))
        {
            ++loc;
            ++ptr;
            //cout << ptr << endl;
        }
        //cout << i << " " << loc << " " << ptr << endl;
        output += (loc+1)/2;
        i=ptr;
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