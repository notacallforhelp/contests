#include<bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int t,n,k,in;
    vector<int>v;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>in;
            v.push_back(in);
        }
        sort(v.begin(),v.end());
 
    vector<long long>prefix(n+1,0);
        prefix[0]=v[0];
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+v[i];
        }
 
    vector<long long> result(n);
        for (int m = 1; m <n; m++) {
            int free_items = (m - 1) / (k + 1);
            int paid_items = m - free_items;
            result[m - 1] = prefix[paid_items];
        }
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}