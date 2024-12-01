#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    
    if(n%2==0)
    {
        cout << "YES\n";
        int c=65;
        for(int i=0;i<n/2;i++)
        {
            cout << (char)c<<(char)c;
            ++c;
            if(c>90)
            {
                c=65;
            }
        }
        cout << endl;
    }
    else
    {
        cout << "NO\n";
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