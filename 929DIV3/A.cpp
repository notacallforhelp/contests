#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>> A[i];
    }

    sort(A.begin(),A.end());

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=abs(A[i]);
    }

    cout << sum << endl;
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