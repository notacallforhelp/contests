#include <bits/stdc++.h>

using namespace std;

void solve1(vector<int> &A,map<int,int> &M,int needed,int n)
{
    int z = needed;
    for(int i=0;i<n;i++)
    {
        if(M[A[i]]==-1)
        {
            cout << A[i] << " ";
            --z;
            if(z<=0)
            {
                cout << endl;
                break;
            }
        }
    }
    z = needed;
    for(int i=0;i<n;i++)
    {
        if(M[A[i]]==-1)
        {
            cout << A[i] << " ";
            --z;
            if(z<=0)
            {
                cout << endl;
                break;
            }
        }
    }
}

void solve2(vector<int> &A,map<int,int> &M,int k,int n)
{
    int tries =k;
    for(int i=0;i<n;i++)
    {
        if(M[A[i]]==-2)
        {
            cout << A[i] << " " << A[i]<<" ";
            tries=tries-2;
            if(tries<=0)
            {
                cout << endl;
                break;
            }
        }
    }
    tries = k;
    for(int i=n;i<2*n;i++)
    {
        if(M[A[i]]==0)
        {
            cout << A[i] << " "<<A[i]<< " ";
            tries = tries-2;
            if(tries<=0)
            {
                cout << endl;
                break;
            }
        }
    }
}

void solve()
{
    int n, k;
    cin>>n>>k;

    int countone = 0;
    int counttwo=0;

    vector<int> A(2*n);

    for(int i=0;i<2*n;i++)
    {
        cin>>A[i];
    }
    map<int,int> M;
    for(int i=0;i<n;i++)
    {
        M[A[i]]++;
        /*cout << M[A[i]] << endl;*/
    }
    for(int i=0;i<n;i++)
    {
        if(M[A[i]]==1)
        {
            ++countone;
            M[A[i]]=-1;
        }
        else if(M[A[i]]==2)
        {
            ++counttwo;
            M[A[i]]=-2;
        }
    }
    /*cout << "one = "<<countone << endl;
    cout <<"two = "<< counttwo<<endl;*/
    if(countone>=2*k)
    {
        solve1(A,M,2*k,n);
    }
    else
    {
        solve2(A,M,2*k,n);
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