#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        ll sum = 0;

        vector<int> A(n);
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            sum += A[i];
        }

        int eleneed = sum/n;
        ll inc = 0;
        bool ok=false;

        for(int i=n-1;i>=0;i--)
        {
            if(A[i]>eleneed&&inc<=0)
            {
                ok=true;
                break;
            }
            else if(A[i]>eleneed)
            {
                int dividend = A[i]-eleneed;
                inc = inc - dividend;

            }
            else if(A[i]<eleneed)
            {
                inc = inc + eleneed-A[i];
            }
            if(inc<0)
            {
                ok=true;
                break;
            }
        }
        if(inc!=0||ok)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}