#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>> n;

    vector<int> A(n);
    int count=0;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(A[i]%3!=0)
        {
            ++count;
        }
        sum+=A[i];
    }

    if(sum%3==0)
    {
        cout << 0 << endl;
        return;
    }
    else if(sum%3==2)
    {
        cout << 1 << endl;
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(sum%3==A[i]%3)
        {
            cout << 1 << endl;
            return;
        }
    }

    if(sum%3==1)
    {
        cout << 2 << endl;
    }


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