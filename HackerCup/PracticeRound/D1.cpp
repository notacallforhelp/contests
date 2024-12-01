#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll absolute(ll a,ll b)
{
    ll output = 0;
    if(a>=b)
    {
        output = a-b;
        return output;
    }
    else
    {
        output = b-a;
        return output;
    }
}

void solve(int caseno)
{
    ll n, g; cin>>n>>g;

    vector<ll> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());

    /*for(auto ele:A)
    {
        cout << ele << " ";
    }

    cout << endl;*/

    ll pos = lower_bound(A.begin(),A.end(),g)-A.begin();
    //cout << pos << endl;

    if(pos==n)
    {
        pos=n-1;
        ll stonenumber = (n-pos);
        ll distance = absolute(g,A[pos]);
        cout << "Case #"<<caseno<<": "<<stonenumber<<" "<<distance<<endl; 
    }
    else
    {
        if((pos-1)>0&&abs(A[pos-1]-g)<abs(A[pos]-g))
        {
            pos = pos-1; 
        }   
        ll stonenumber=(n-pos);
        ll distance = absolute(g,A[pos]);
        cout << "Case #"<<caseno<<": "<<stonenumber<<" "<<distance<<endl;
    }
}

int main()
{
    //freopen("line_of_delivery_part_1_input.txt","r",stdin);
    //freopen("output7.txt","w",stdout);
    int t; cin>>t;
    int caseno = 1;
    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}