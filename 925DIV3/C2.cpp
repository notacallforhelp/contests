#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> A(n);

    for(int i=0;i<n;i++)
    {   
        cin>>A[i];
    }

    if(n==1)
    {
        cout << 0 << endl;
        return;
    }
    int left=0;
    int right = n-1;
    while(left<=n-1&&A[left]==A[left+1])
    {
        ++left;
    }
    while(right>=0&&A[right]==A[right-1])
    {
        --right;
    }
    /*cout << left<< " " << right<<endl<<endl;*/
    if(right<left)
    {
        cout << 0 <<endl;
    }
    else if(A[right]==A[left])
    {
        cout << (right-1)-(left+1)+1<<endl;
    }
    else
    {
        int elecostleft = (n-1)-(left+1)+1;
        int elecostright = (right-1)-0+1;
        cout << min(elecostleft,elecostright) <<endl;
    }
    
}

int main()
{
    int t;
    cin>> t;

    while(t--)
    {
        solve();
    }
}