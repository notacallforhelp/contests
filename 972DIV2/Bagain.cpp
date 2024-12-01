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

    if(d_cell<c1&&d_cell<c2)
    {
        cout << min(c1,c2)-1 << endl;
    }
    else if(d_cell>c2 && d_cell>c2)
    {
        cout << n-max(c1,c2) << endl;
    }
    else
    {
        if(c1>c2)
        {
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }
        cout << (int)ceil(((c2-c1)/2.0)) << endl;
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