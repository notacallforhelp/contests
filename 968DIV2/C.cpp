#include <bits/stdc++.h>

using namespace std;

int hsh[26];

void solve()
{
    int n; cin>>n;
    string s;cin>>s;

    

    for(int i=0;i<s.size();i++)
    {
        ++hsh[(int)s[i]-97];
    }

    /*for(auto k:hsh)
    {
        cout << k << " ";
    }

    cout << endl;*/

    int cnt = s.size();

    while(cnt)
    {
        for(int i=0;i<26;i++)
        {
            if(hsh[i]>0)
            {
                cout << (char)(i+97);
                --hsh[i];
                --cnt;
            }
        }
    }

    cout << endl;
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