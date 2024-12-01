#include <bits/stdc++.h>

typedef long long int ll;
typedef long double ld;

using namespace std;


void solve()
{
    int n; cin>>n; int k; cin>>k;
    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    bool flag_allk = true;
    bool flag_allkmultiple=true;

    vector<pair<int,int>> segments;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]!=k)
        {
            flag_allk=false;
        }
        if(__gcd(A[i],k)!=k)
        {
            flag_allkmultiple=false;
        }
    }

    if(flag_allk)
    {
        cout << 0 << endl;
        return;
    }

    if(flag_allkmultiple)
    {
        cout << 1 << endl;
        return;
    }

    int left = 0;
    int right = 0;

    while(right<n)
    {
        if(A[right]!=k)
        {
            while(right+1<n&&A[right+1]!=k)
            {
                ++right;
            }
            segments.push_back({left,right});
        }
        ++right;
        left = right;
    }

    if(segments.size()==1)
    {
        bool flag = true;
        for(int i=segments[0].first;i<=segments[0].second-1;i++)
        {
            if(A[i]!=A[i+1])
            {
                flag = false;
            }
        }

        if(flag)
        {
            cout << 1 << endl;
            return;
        }
    }

    cout << 2 << endl;
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
