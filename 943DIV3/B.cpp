#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin>>n>>m;

    string a;
    string b;
    cin>>a>>b;
    int output = 0;

    int hsh[2];
    hsh[0]=hsh[1]=0;
    for(int i=0;i<b.size();i++)
    {
        ++hsh[b[i]-48];
    }
    //cout << hsh[0] <<" " << hsh[1] << endl;
    for(int i=0;i<a.size();i++)
    {
        if(hsh[a[i]-48]>0)
        {
            --hsh[a[i]-48];
            ++output;
        }
        else
        {
            break;
        }
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