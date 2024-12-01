#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> A(n);

    int hsh[101];
    for(int i=0;i<101;i++)
    {
        hsh[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        ++hsh[x];
    }
    int output = 0;

    for(int i=0;i<101;i++)
    {
        output += hsh[i]/3;
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