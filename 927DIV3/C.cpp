#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> A(n);
    vector<int> B(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    string S;
    cin>>S;

    int right = n-1;
    int left = 0;

    for(int i=0;i<S.size();i++)
    {
        if(S[i]=='R')
        {
            B[n-1-i]=A[right];
            --right;
        }
        else
        {
            B[n-1-i]=A[left];
            ++left;
        }
    }

    /*for(auto ele: B)
    {
        cout << ele << " ";
    }
    cout << endl;*/

    ll current = 1;
    vector<ll> C(n);
    for(int i=0;i<n;i++)
    {
        current = (current%m*B[i]%m)%m;
        C[n-1-i]=current;
    }

    for(auto ele:C)
    {
        cout << ele << " ";
    }
    cout << endl;
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