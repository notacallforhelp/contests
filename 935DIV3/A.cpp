#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void solve()
{
        ll a, b, c;
        cin>>a>>b>>c;

        if(b%3==0)
        {
            ll result = a+(b/3)+(c/3);
            if(c%3!=0)
            {
                ++result;
            }
            cout << result<<endl;
        }
        else
        {
            if(b%3!=0)
            {
                ll required = 3-b%3;
                if(required>c)
                {
                    cout << -1<<endl;
                    return;
                }
                else
                {
                    ll result = a + (b/3+1) + (c-required)/3;
                    if((c-required)%3!=0)
                    {
                        result = result + 1;
                    }
                    cout << result << endl;
                }
            }
        }

        /*ll required = 3-(b%3);
        if(required>c)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            ll result = a + (3-(b%3)+b)/3 + (c-(3-(b%3)))/3 + (c-(3-(b%3)))%3;
            cout << result << endl;
        }*/
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