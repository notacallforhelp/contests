#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m , q;
    cin>>n>>m>>q;

    int c1,c2;
    cin>>c1>>c2;

    int d_cell;
    cin>>d_cell;

    if(d_cell<min(c1,c2))
    {
        cout << min(c1,c2)-1 << endl;
    }
    else if(d_cell>max(c1,c2))
    {
        cout << n-max(c1,c2) << endl;
    }
    else
    {
        cout << (max(c1,c2)-min(c1,c2))/2 << endl;
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