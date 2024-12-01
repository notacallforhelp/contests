#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> V(n);
    for(int i=n-1;i>=0;i--)
    {
        cin>>V[i];
    }

    for(auto ele:V)
    {
        cout<<ele<<" ";
    }
    cout << endl;

}