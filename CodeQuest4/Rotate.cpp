#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    int k;
    cin >> k;

    for(int i=0;i<n;i++)
    {
        if(i<k)
        {
            int new_pos = (i-k+n);
            B[new_pos]=A[i];
        }
        else
        {
            int new_pos = (i-k);
            B[new_pos]=A[i];
        }
    }

    for(auto &val: B)
    {
        cout << val << " ";
    }
    cout << endl;



    
}