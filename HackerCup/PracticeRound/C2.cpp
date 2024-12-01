#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


void solve(int caseno)
{
    ll n; cin>>n;

    vector<pair<ll,ll>> points (n);
    ll smallest_x = LLONG_MAX;
    ll smallest_y = LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>points[i].first>>points[i].second;
        if(points[i].first<smallest_x)
        {
            smallest_x = points[i].first;
        }
        if(points[i].second<smallest_y)
        {
            smallest_y=points[i].second;
        }
    }
    //cout << smallest_x << " " << smallest_y << endl;
    for(int i=0;i<n;i++)
    {
        points[i].first += abs(smallest_x);
        points[i].second += abs(smallest_y);
    }

    /*for(auto ele:points)
    {
        cout << ele.first << " " << ele.second << endl;
    }*/

   map<pair<ll,ll>,ll> M;

   ll totaleleonsameline=0;

   for(ll i=0;i<n;i++)
   {
    for(ll j=i+1;j<n;j++)
    {
        
    }
   }

   for(ll i=0;i<n;i++)
   {
    ll nr = points[i].second-points[0].second;
    ll dr = points[i].first-points[0].first;
    ll commondiv = __gcd(nr,dr);
    nr = nr/commondiv;
    dr = dr/commondiv;
    ++M[{nr,dr}];
    if(totaleleonsameline<M[{nr,dr}])
    {
        totaleleonsameline = M[{nr,dr}];
    }
   }
   cout <<"Case #"<<caseno<<": "<< n-(totaleleonsameline+1)<< endl;
}

int main()
{
    freopen("fall_in_line_validation_input.txt","r",stdin);
    freopen("output9.txt","w",stdout);

    int t; cin>>t;

    int caseno=1;

    while(t--)
    {
        solve(caseno);
        ++caseno;
    }
}