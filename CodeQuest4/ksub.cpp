#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int m = 5*1e6+1;
vector<ll> A(m);
vector<ll> pf(m);

int main()
{
    int n;
    ll k;
    cin >> n >> k;

    

    for(int i=1;i<=n;i++)
    {
        cin >> A[i];
        pf[i]=pf[i-1]+A[i];
    }

    int count = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((pf[j]-pf[i-1])==k&&(j-i+1)>count)
            {
                count = j-i+1;
            }
        }
    }

    cout << count << endl;

    

    

}