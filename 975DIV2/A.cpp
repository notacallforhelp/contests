#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

void solve()
{
    int n; cin>>n;

    vector<int> A(n);

    int mxodd=0;
    int mxeve=0;
    int mxpos=-1;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(i%2==0)
        {
            mxeve = max(mxeve,A[i]);
        }
        else
        {
            mxodd = max(mxodd,A[i]);
        }
    }

    cout << max((mxeve+n%2+n/2),(mxodd+n/2))<<endl;

}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}