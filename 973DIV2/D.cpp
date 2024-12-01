#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}

void solve()
{
    int n;
    cin>>n;

    vector<ll> A(n);

    ll sumright=0;


    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(i>0)
        {
            sumright += A[i];
        }
    }
    //cout << sumright << endl;
    if(n==1)
    {
        cout << 0 << endl;
        return;
    }
    ll divaftersum = sumright/(n-1);
    ll ceilval=ceil2(sumright,n-1);
    ll floorval=sumright/(n-1);
    //cout << A[0] << " " << floorval << " " << ceilval << " " << endl; 

    if(A[0]<=divaftersum)
    {
        cout << max(ceilval,floorval)-A[0] << endl;
        return;
    }

    while(A[0]>divaftersum)
    {
        --A[0];
        ++sumright;
        divaftersum = sumright/(n-1);
        ceilval=ceil2(sumright,n-1);
        floorval=sumright/(n-1);
        //cout << A[0] << " " << floorval << " " << ceilval << " " << endl; 
    }
    cout << max(ceilval,A[0])-min(A[0],floorval)<< endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}