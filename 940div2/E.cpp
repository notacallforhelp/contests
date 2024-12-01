#include <bits/stdc++.h>

using namespace std;

long long int fact[100];

void solve()
{
    int n;cin>>n;
    int output = 0;
    for(int i=1;i<=n;i++)
    {
        int start=fact[i];
        for(int j=1;j<=i;j++)
        {
            output += ((start/j)/(fact[i-j]))%j;
        }
    }
    cout << output << endl;
}

int main()
{

    fact[0]=fact[1]=1;
    for(int i=2;i<=99;i++)
    {
        fact[i]=fact[i-1]*1LL*i;
    }
    int t;cin>>t;

    while(t--)
    {
        solve();
    }
}