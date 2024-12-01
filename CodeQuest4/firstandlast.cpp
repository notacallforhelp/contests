#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, target;
    cin>> n >> target;
    vector<int> A(n);

    int l=-1, r = -1;

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
        if(A[i]==target)
        {
            if(l==-1)
            {
                l=i;
            }
            r=i;
        }
    }

    cout << l << " "<<r << endl;


}