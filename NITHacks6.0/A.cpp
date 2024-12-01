#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll x;
        cin >> x;
        ll term=0;
        ll divisor = 1e9+7;
        
        ll compare = 1;
        for(int i=0;i<x;i++)
        {
            compare = ((compare%divisor)*10)%divisor;
        }
        ll output = 0;
        ll multiplier = 2;

        while(term <= compare)
        {
            term = 3*(multiplier%divisor)%divisor;
            ++output;
            ++ multiplier;
            output = output%divisor;
        }


        cout << output << endl;
        /*cout << compare << endl;*/
    }
}