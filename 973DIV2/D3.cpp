#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[200200];
int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stack<pair<ll,int>> s;

    for(int i=1;i<=n;i++)
    {
        ll sum = a[i], cnt = 1;
        while(s.size()&&s.top().first>=sum/cnt)
        {
            sum += s.top().first*s.top().second;
            cnt += s.top().second;
            s.pop();
        }
        s.push({sum/cnt,cnt-sum%cnt});
        if(sum%cnt!=0)
        {
            s.push({sum/cnt+1,sum%cnt});
        }
    }

    ll mx = s.top().first;

    while(s.size()>1)
    {
        s.pop();
    }

    cout << mx - s.top().first << endl;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}