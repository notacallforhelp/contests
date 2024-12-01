#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;

    for(int j=1;j<=n;j++)
    {
        ++sum;
        for(int i=2;i<=j;i++)
        {
            if(j%i==0)
            {
                sum +=i;
            }
        }
    }

    cout <<sum << endl;
}