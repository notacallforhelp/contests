#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    ll n, d, k; cin>>n>>d>>k;
    vector<pair<ll,ll>> A(k);

    for(int i=0;i<k;i++)
    {
        cin>>A[i].first>>A[i].second;
    }

    sort(A.begin(),A.end());
    ll mnVal = LLONG_MAX;
    ll mxVal = LLONG_MIN;
    ll mnIdx = -1;
    ll mxIdx = -1;

    multiset<ll> currentjobendtime;

    for(ll day=1,idx=0;day+d-1<=n;day++)
    {
        while(idx<k&&A[idx].first<=day+d-1)
        {
            currentjobendtime.insert(A[idx].second);
            ++idx;
        }

        while(!currentjobendtime.empty()&&*currentjobendtime.begin()<day)
        {
            currentjobendtime.erase(currentjobendtime.begin());
        }
        ll currentoverlap = currentjobendtime.size();
        if(mnVal>currentoverlap)
        {
            mnVal = currentoverlap;
            mnIdx = day;
        }
        if(mxVal < currentoverlap)
        {
            mxVal = currentoverlap;
            mxIdx = day;
        }
    }

    cout << mxIdx << " " << mnIdx << endl;

}

int main()
{
    int t;cin>>t;

    while(t--)
    {
        solve();
    }
}