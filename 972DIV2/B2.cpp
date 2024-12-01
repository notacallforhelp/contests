#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<int> pos(m);

    for(int i=0;i<m;i++)
    {
        cin>>pos[i];
    }

    sort(pos.begin(),pos.end());

    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;

        int k = upper_bound(pos.begin(),pos.end(),x)-pos.begin();

        if(k==m)
        {
            cout << n-pos[m-1] << endl;
        }
        else if(k==0)
        {
            cout << pos[0]-1 << endl;
        }
        else
        {
            cout << (pos[k]-pos[k-1])/2<<endl;
        }
    }
    
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