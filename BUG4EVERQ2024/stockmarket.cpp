#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> A(n);
    vector<int> perf(n,1);
    stack<int> s;
    int local = 0;
    int global = 0;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    for(int i=0;i<n;i++)
    {        
        while(s.size()&&s.top()<=A[i])
        {
            ++perf[i];
            s.pop();
        }
        if(global<A[i])
        {
            global = A[i];
            while(s.size())
            {
                s.pop();
            }
        }
        s.push(A[i]);
    }

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}