#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n>>k;

    int A[n+1];

    for(int i=1;i<=n;i++)
    {
        A[i]=1;
    }

    A[k]=0;
    int step = k;

    int ct = 1;

    while(ct!=n-1)
    {
        if(k+step<=n)
        {
            k += step;
            A[k]=0;
            ++ct;
        }
        else
        {
            k = (k+step)-n;
            A[k]=0;
            ++ct;
        }
        if(ct==n-1)
        {
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        
        cout << A[i] <<" ";
        
    }
    cout << endl;

    for(int i=1;i<=n;i++)
    {
        if(A[i]==1)
        {
            cout << i << endl;
        }
    }
}