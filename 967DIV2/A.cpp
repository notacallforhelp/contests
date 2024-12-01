#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> A(n);

     map<int,int> M;

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        ++M[A[i]];
    }

    int highest_ct=0;
    //int highest_num=0;

    for(auto &ele:M)
    {
        if(highest_ct<ele.second)
        {
            //highest_num=ele.first;
            highest_ct=ele.second;
        }
    }

    //cout << highest_num << endl;

    cout << A.size()-highest_ct << endl;


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