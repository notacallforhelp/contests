#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve(int caseno)
{
    ll n, k; cin>>n>>k;

    vector<ll> A(n);

    ll min_ele=INT_MAX;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        min_ele = min(min_ele,A[i]);
    }
    ll output;
    if(n<3)
    {
        output=min_ele;
    }
    else
    {
        output = min_ele*(n-2)*2+min_ele;
    }

    //cout << output << endl;

    if(k>=output)
    {
        cout << "Case #"<<caseno<<": YES\n";
    }
    else
    {
        cout << "Case #"<<caseno<<": NO\n";
    }
}

int main()
{
    int t;
    cin>>t;

    int caseno=1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}