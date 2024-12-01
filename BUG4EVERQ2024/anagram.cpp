#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin>>n;

    set<string> A;
    for(int i=0;i<n;i++)
    {
        string k; cin>>k;
        sort(k.begin(),k.end());
        A.insert(k);
    }

    cout << A.size() << endl;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}