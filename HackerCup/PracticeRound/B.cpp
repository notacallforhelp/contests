#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const double eps = 1e-6;

void solve(int caseno)
{
    ll n, p; cin>>n>>p;

    long double probab = p/100.0;
    long double arg = 1;


    for(int i=1;i<=n-1;i++)
    {
        arg *= probab;
    }
    long double root = 1.0/(long double)n;
    //cout << root << endl;

    arg = pow(arg, root);
    arg = arg * 100;
    
    //cout<<setprecision(9)<< arg-p << endl;
    cout << "Case #"<<caseno<<": "<<fixed<<setprecision(9)<< arg-p << endl;

}

int main()
{
    int t;cin>>t;
    int caseno=1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}