#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

double exp(double, double);
double n_root_(double, double);

void solve(int caseno)
{
    ll n, p; cin>>n>>p;

    long double probab = p/100.0;
    long double arg = exp(probab,n-1);
    arg = n_root_(arg,n);
    
    cout << (arg-probab)*100<< endl;

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


double exp(double a, double b){
    double t(1);
    for(int i = 0;i<b;++i)
        t *= a;
    return t;
}
double n_root_(double num, double n_){
    double x;
    double A(num);
    double dx;
    double eps(10e-6);
    double n(n_);
    x = A * 0.5;
    dx = (A/exp(x,n-1)-x)/n;
    while(dx >= eps || dx <= -eps){
        x = x + dx;
        dx = (A/exp(x,n-1)-x)/n;
    }
   return x;
}