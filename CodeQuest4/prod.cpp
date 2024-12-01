#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    vector<ll> A(n);
    ll mult = 1;

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
        mult *= A[i];
    }

    for(int i=0;i<n;i++)
    {
        cout << mult/A[i] << " ";
    }
    cout << endl;
}