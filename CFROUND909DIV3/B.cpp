#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int m = 1e6*1.6;
ll pf[m];
ll A[m];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n==1)
        {
            cin >> A[0];
            cout << 0 << endl;
        }
        else
        {
            pf[0]=0;

            for(int i=1;i<=n;i++)
            {
                cin >> A[i];
                pf[i]=pf[i-1]+A[i];
            }
            
            ll global_diff = 0;

            for(int i=1;i<=n/2;i++)
            {
                if(n%i!=0)
                {
                    continue;
                }
                else
                {
                    ll local_max = -1e18;
                    ll local_min = 1e18;
                    ll local_diff=0;
                    int l = 1;
                    int r = i;
                    while(r<=n)
                    {
                        local_min = min(local_min,pf[r]-pf[l-1]);
                        local_max = max(local_max,pf[r]-pf[l-1]);
                        r=r+i;
                        l=l+i;
                    }
                    local_diff = local_max-local_min;
                    global_diff = max(global_diff,local_diff);
                }
            }
            cout << global_diff << endl;
        }

    }
}