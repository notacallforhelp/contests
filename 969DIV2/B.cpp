#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    int n, m;
    cin>>n>>m;
    int x;
    int maxi = -1;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        maxi = max(maxi,x);
    }

    for(int i=0;i<m;i++)
    {
        char c;
        int l;
        int r;
        cin>>c>>l>>r;
        if(c=='+')
        {
            if(maxi>=l&&maxi<=r)
            {
                ++maxi;
            }
        }
        else
        {
            if(maxi>=l&&maxi<=r)
            {
                --maxi;
            }
        }
        cout << maxi << " ";
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