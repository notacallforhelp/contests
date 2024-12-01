#include <bits/stdc++.h>

using namespace std;

const int m = 2e5+10;
bool check[m];
bool currcheck[m];

void solve()
{
    int n;
    cin>>n;
    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        check[A[i]]=true;
    }
    int mex;
    for(int i=0;i<m;i++)
    {
        if(check[i]==false)
        {
            mex = i;
            break;
        }
    }
    
    int global=n;
    int local=0;
    int currentmex=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==currentmex)
        {
            ++currentmex;
        }
        if(A[i]<mex)
        {
            ++local;
        }
        else
        {
            local=0;
            currentmex=0;
        }
        if(i!=0&&A[i]==A[i-1])
        {
            --local;
        }
        if(currentmex==mex)
        {
            global=min(local,global);
            local=0;
            currentmex=0;
        }
    }
    if(global==0)
    {
        cout << 1 << endl;
        return;
    }
    cout << global << endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

}