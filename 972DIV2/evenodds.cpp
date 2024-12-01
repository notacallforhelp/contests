#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


int main()
{
    ll n, k; cin>>n>>k;

    ll pos;


    if(n%2==0)
    {
        if(k<=n/2)
        {
            cout << k*2 -1 << endl;
        }
        else
        {
            if(k==n)
            {
                k=n-(n/2);
            }
            else
            {
                k=k%(n/2);
            }
            cout << k*2 << endl;
        }
    }
    else
    {
        if(k<=n/2+1)
        {
            cout << k*2 -1 << endl;
        }
        else
        {
            if(k==n)
            {
                k=n-(n/2)-1;
            }
            else
            {
                k=k%(n/2)-1;
            }
            cout << k*2 << endl;
        }
    }
}