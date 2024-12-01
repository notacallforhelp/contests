#include <bits/stdc++.h>
using namespace std;
int main()
{
string s;int n;char c;cin>>n>>s;c=s[0];
map<char,int> mp;
mp['K'] = 1;mp['M'] = 2;mp['G'] = 3;mp['T'] = 4;mp['P'] = 5;mp['E'] = 6;mp['Z'] = 7;mp['Y'] = 8;
float ans = 1.0;
for (int i = 0; i < mp[s[0]]-1; i++) {
ans/=1.024;
}ans = ans*n;
if(ans*100 <100){
ans*=1000;
c = 'E';
}
else
ans/=1.024;cout<<setprecision(2)<<fixed<<ans<<' '<<c<<'i'<<'B';return 0;
cout<<"double siq[PREFIXES],b2q[PREFIXES];for(i=1;i<PREFIXES;i++)";
}