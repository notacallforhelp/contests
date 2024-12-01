#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;

    int g = __gcd(a,b);

    vector<int> C(n);

    for(int i=0;i<n;i++)
    {
        cin>>C[i];
        C[i]%=g;
    }


    sort(C.begin(),C.end());


    int res = C[C.size()-1]-C[0];

    for(int i=1;i<C.size();i++)
    {
        res = min(res,C[i-1]+g-C[i]);
    }

    cout << res << endl;
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