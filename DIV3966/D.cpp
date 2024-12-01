#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    int n;
    cin>>n;

    vector<ll> A(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }

    ll prefix[n+1];
    prefix[0]=0;

    for(int i=1;i<=n;i++)
    {
        prefix[i] = prefix[i-1]+A[i];
    }

    string s;
    s.push_back('0');
    for(int i=0;i<n;i++)
    {
        char x;
        cin>>x;
        s.push_back(x);
    }

    //cout << s << endl;

    int left=1;
    int right=n;
    ll output = 0;

    while(left<=n&&right>=1&&left<right)
    {
        if(s[left]=='L'&&s[right]=='R')
        {
            //cout << left << " " << right << endl;
            output += prefix[right]-prefix[left-1];
            ++left;
            --right;
            continue;
        } 
        if(s[left]=='L'&&s[right]!='R')
        {
            --right;
            continue;
        }
        if(s[left]!='L'&&s[right]=='R')
        {
            ++left;
            continue;
        }
        if(s[left]!='L'&&s[right]!='R')
        {
            ++left;
            --right;
        }
    }

    cout << output << endl;
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