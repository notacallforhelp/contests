#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin>>n>>k;

    int output = 0;

    if(k!=0)
    {
        output++;
        k=k-n;
    }
    else
    {
        cout << 0 << endl;
        return;
    }

    int reduce = n-1;

    while(k>0&&reduce>=1)
    {
        ++output;
        k=k-reduce;

        if(k>0)
        {
            ++output;
            k=k-reduce;
        }

        --reduce;
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