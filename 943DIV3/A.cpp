#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x;
    cin>>x;

    int maxi = 0;
    int output = 0;
    

    for(int i=1;i<x;i++)
    {
        if(__gcd(x,i)+i>maxi)
        {
            maxi = __gcd(x,i)+i;
            output = i;
        }
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