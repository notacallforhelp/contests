#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b , l;
    cin>>a>>b>>l;

    set<int> S;

    for(int i=0;i<32;i++)
    {
        int x = l;
        bool val = false;

        for(int k=0;k<i;k++)
        {
            if(x%a)
            {
                val=true;
                break;
            }
            x=x/a;
        }
        if(val)
        {
            break;
        }

        while(true)
        {
            S.insert(x);
            if(x%b)
            {
                break;
            }
            x=x/b;
        }
    }
    cout << S.size()<<endl;
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