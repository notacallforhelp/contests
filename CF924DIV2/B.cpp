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

        set<ll> S;
        vector<ll> A;

        for(int i=0;i<n;i++)
        {
            int val;
            cin >> val;
            S.insert(val);
        }

        for(auto &ele: S)
        {
            A.push_back(ele);
        }

        ll l_p = 0, k=0;
        ll g_count=0;
        ll l_count = 0;

        while(k<A.size())
        {
            if(A[k]-A[l_p]<n)
            {
                ++l_count;
                ++k;
                g_count = max(g_count,l_count);
            }
            else
            {
                l_count = 0;
                l_p=l_p+1;
                k = l_p;
            }
            /*cout << l_count << endl;*/
        }

        cout << g_count << endl;

    }
}