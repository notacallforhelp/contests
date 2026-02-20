#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int N = 50000;
vector<int> divisors[N+10];

void find_divisors()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}


void solve()
{   
   int n,k; cin>>n>>k;
   //k rows, n cols
   vector<string> grid(k);
   vector<vector<int>> presence (n,vector<int>(26,0)); //presence[i][c] c char in ith col

   for(int i=0;i<k;i++)
   {
        cin>>grid[i];
   }

   for(int j=0;j<n;j++)
   {
        for(int i=0;i<k;i++)
        {
            int p = grid[i][j]-'a';
            presence[j][p]=1;
        }
   }

   for(auto &d:divisors[n])
   {
        string s="";
        bool pass = true;
        for(int i=0;i<d;i++)
        {
            bool h = false;
            for(int c=0;c<26;c++)
            {
                bool found = true;
                for(int pos=i;pos<n;pos+=d)
                {
                    if(presence[pos][c]==0)
                    {
                        found = false;
                        break;
                    }
                }
                if(found)
                {
                    h = true;
                    char ch = c+'a';
                    s.push_back(ch);
                    break;
                }
            }
            if(!h)
            {
                pass=false;
                break;
            }
        }
        if(pass)
        {
            //cout << d << "\n";
            for(int i=0;i<(n/d);i++)
            {
                cout << s;
            }
            cout << "\n";
            return;
        }  
   }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    find_divisors();
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}