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
        
        sort(A.begin(),A.end());
        
        cout << A[n/2] << endl;
    }
     
    int main()
    {
        int t; cin>>t;
        while(t--)
        {
            solve();
        }
    }