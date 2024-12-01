#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b , l;
    cin >> a >> b >> l;
    set<int> ans;

    for(int i=0;i<=34;i++)
    {
        int x = l;
        bool fail = false;
        for(int k=0;k<i;k++)
        {
            if(x%a)
            {
                fail = true;
                break;
            }
            x = x/a;
        }
        if(fail)
        {
            break;
        }
        while(true)
        {
            ans.insert(x);
            if(x%b)break;
            x=x/b;
        }
    }
    cout << ans.size()<<endl;

    
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