#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    ll b,c,d; cin>>b>>c>>d;
    ll flag = 1;
    ll mask = 1;

    ll a= 0;

    ll bit_b=0;
    ll bit_c=0;
    ll bit_d=0;

    for(ll i=0;i<62;i++)
    {
        if(b&mask) bit_b=1;
        else bit_b=0;

        if(c&mask) bit_c=1;
        else bit_c=0;

        if(d&mask) bit_d=1;
        else bit_d=0;

        if((bit_b&&(!bit_c)&&(!bit_d)) || ((!bit_b)&&bit_c&&bit_d))
        {
            flag=0;
            break;
        }

        if(bit_b&&bit_c)
        {
            a += (1ll-bit_d)*mask;
        }
        else
        {
            a += bit_d*mask;
        }
        //cout << "b" << endl;
        mask <<= 1;
    }

    if(flag)
    {
        cout << a << endl;
    }
    else
    {
        cout <<-1<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}