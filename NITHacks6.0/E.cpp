#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        int evenct=0;
        int oddct = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)
            {
                ++evenct;
            }
            else
            {
                ++oddct;
            }
        }
        /*cout << oddct << endl;*/
        if(oddct==0)
        {
            cout << "NO\n";
        }
        else if(evenct>=1)
        {
            if((oddct-1)%2==0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
        else
        {
            if(oddct%2==0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}