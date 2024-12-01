#include <bits/stdc++.h>

using namespace std;


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> suf(s.size()+1);
    for(int i=0;i<suf.size();i++)
    {
        suf[i]=0;
    }

    for(int i=s.size()-1;i>=0;i--)
    {
        suf[i]=suf[i+1]+(s[i]=='1');
    }

    int pref_cnt=0;
    int opt_ans=-1;
    int opt_dist=n*2;
    int thresshold=(n+1)/2;
    for(int i=0;i<n+1;i++)
    {
        if(pref_cnt>=(i+1)/2&&suf[i]>=(n-i+1)/2&&abs(n-2*i)<opt_dist)
        {
            opt_dist=abs(n-2*i);
            opt_ans=i;
        }
        if(i!=n)
        {
            pref_cnt+=(s[i]=='0');
        }
    }
    cout << opt_ans << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}