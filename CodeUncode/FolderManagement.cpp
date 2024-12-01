#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n, x;
    cin>>n>>x;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    ll sum=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(sum+A[i]>x)
        {
            break;
        }
        sum += A[i];
        ++count;
    }
    cout << count << endl;
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