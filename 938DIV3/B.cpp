#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,c,d;
    cin>>n>>c>>d;
    vector<int> A(n*n);
    for(int i=0;i<n*n;i++)
    {
        cin>>A[i];
    }
    int countc=0;
    int countd=0;
    for(int i=0;i<n*n;i++)
    {
        for(int j=i+1;j<n*n;j++)
        {
            /*cout << abs(A[i]-A[j])<< endl;*/
            if((int)abs(A[i]-A[j])==c)
            {
                ++countc;
            }
            if((int)abs(A[i]-A[j])==d)
            {
                ++countd;
            }
        }
    }
    cout << countc << " " << countd << endl;
    /*if(countc==n*(n-1)&&countd==n*(n-1)||countc==2*n*(n-1)&&countd==2*n*(n-1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }*/

    if(countc>=n*(n-1)&&countd>=n*(n-1))
    {
        if(countc==countd)
        {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";


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