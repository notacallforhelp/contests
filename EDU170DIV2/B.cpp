#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef long double ld;


const int mod = 1e9+7;
const int hik=1e5+10;

int A[hik];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    A[0]=1;

    for(int i=1;i<1e5;i++)
    {
        A[i]=(A[i-1]*2)%mod;
    }

    int t; cin>>t;

    vector<int> n(t);
    vector<int> k(t);

    for(int i=0;i<t;i++)
    {
        cin>>n[i];
    }
    for(int i=0;i<t;i++)
    {
        cin>>k[i];
    }

    for(int i=0;i<t;i++)
    {
        cout << A[k[i]]<<endl;
    }
}