#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(n==0&&m==0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> A(n);
    vector<int> B(m);

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> B[i];
    }
    int i=0,j=0,k=0;
    vector<int> M(n+m);

    while(i<n&&j<m)
    {
        if(A[i]<=B[j])
        {
            M[k]=A[i];
            ++i;
            ++k;
        }
        else
        {
            M[k]=B[j];
            ++j;
            ++k;
        }
    }

    while(i<n)
    {
        M[k]=A[i];
        ++k;
        ++i;
    }
    while(j<m)
    {
        M[k]=B[j];
        ++k;
        ++j;
    }

    int o = M.size();
    if(o%2!=0)
    {
        cout << M[o/2] << endl;
    }
    else
    {
        cout << (M[o/2]+M[o/2-1])/2.0 << endl;
    }


}