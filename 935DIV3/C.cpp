#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;
    int wol=0;
    int hol=0;
    int hor=n;
    int wor=0;
    vector<int> possibilities;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ++wor;
        }
    }
    int output=INT_MIN;
    for(int i=0,ptr=-1;i<=n;i++,ptr)
    {
        if(2*wol>=hol&&2*wor>=hor)
        {
            if(abs(n/2-i)<=abs(n/2-output))
            {
                output=i;
            }
        }
        if(ptr!=n&&ptr!=n+1)
        {
            int d =s[ptr+1]-48;
            if(d==0)
            {
                ++wol;
            }
            else
            {
                --wor;
            }
        }
        ++hol;
        --hor;
    }
    cout << output << endl;

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