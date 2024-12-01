#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int left=0;
    int right=n-1;
    int count=0;

    while(k>0&&left<=right)
    {
        int leftship = A[left];
        int rightship = A[right];
        if(left==right)
        {
            if(k>=leftship)
            {
                ++count;
                break;
            }
            else
            {
                break;
            }
        }
        if(leftship==rightship&&k>=2*leftship-1)
        {
            A[left]=0;
            ++left;
            A[right]=0;
            ++count;
            k=k-(2*leftship-1)-1;
        }
        else if(leftship<rightship&&k>=2*leftship-1)
        {
            A[right]=A[right]-A[left];
            A[left]=0;
            ++left;
            ++count;
            k=k-(2*leftship-1)-1;
        }
        else if(leftship>rightship&&k>=2*rightship)   //leftship>rightship
        {
            A[left]=A[left]-A[right];
            A[right]=0;
            --right;
            ++count;
            k=k-(2*rightship);
        }
        else
        {
            break;
        }
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