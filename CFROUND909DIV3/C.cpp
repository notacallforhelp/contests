#include <bits/stdc++.h>

using namespace std;

const int m = 1e5*3;
int hsh[m];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int A[m];

        for(int i=0;i<m;i++)
        {
            hsh[i]=0;
        }

        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]==2)
            {
                ++hsh[1];
            }
            else
            {
                ++hsh[A[i]];
            }
        }

        int output = 0;

        for(int i=1;i<m;i++)
        {
            if(hsh[i]>=2)
            {
                output += (hsh[i]*(hsh[i]-1)/2);
            }
        }

        cout << output << endl;

        
    }
}