#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &A,int n,string s)
{
    if(s.size()!=A.size())
    {
        cout << "NO\n";
        return;
    }

    map<int,vector<int>> M;

    for(int i=0;i<A.size();i++)
    {
        M[A[i]].push_back(i);
    }

    for(auto &ele:M)
    {
        char temp =' ';
        for(auto k:ele.second)
        {
            if(temp==' ')
            {
                temp=s[k];
            }
            else
            {
                if(temp!=s[k])
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    map<char,vector<int>> G;

    for(int i=0;i<s.size();i++)
    {
        G[s[i]].push_back(i);
    }

    for(auto &ele:G)
    {
        int temp = 0;
        for(auto k:ele.second)
        {
            if(temp==0)
            {
                temp=A[k];
            }
            else
            {
                if(temp!=A[k])
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> A(n);

        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }

        int q;
        cin>>q;

        while(q--)
        {
            string s;
            cin>>s;
            solve(A,n,s);
        }
    }
}