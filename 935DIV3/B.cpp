#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    ll a, b, m;
    cin>>a>>b>>m;
    ll count=0;

    /*ll lcm = m/(b/(a/((__gcd(__gcd(a,b),m)))));
    cout << lcm << endl;

    ll current = lcm;
    while(lcm-current<=(m+1)&&current>=0)
    {
        ++count;
        current = current -a;
    }
    current = lcm;
    while(lcm-current<=(m+1)&&current>=0)
    {
        ++count;
        current = current -b;
    }

    cout << count << endl;*/

    cout << (m/a)+(m/b)+2<<endl;

}

int main()
{
    int t;
    cin>> t;

    while(t--)
    {
        solve();
    }
}