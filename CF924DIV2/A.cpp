#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        if(a%2!=0&&b%2!=0)
        {
            cout << "No\n";
        }
        else if((a%2!=0&&b%2==0)|(a%2==0&&b%2!=0))
        {
            if(a*2==b||b*2==a)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }

        }
        else
        {
            cout << "Yes\n";
        }
    }
}