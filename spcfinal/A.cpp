#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
typedef long long ll;
typedef long double ld;

//ordered_sets
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//struct for range 
struct range
{
    int l,r,index;
    bool operator < (const range &other) const
    {
        if(l==other.l)
            return r>other.r;
        return l < other.l;
    }
};

/*
FOR SIMULATING ALL CELLS THAT SHARE A WALL WITH CURRENT CELL, GRID IS OF SIZE N*M

int dx[]={-1,0,+1,0};
int dy[]={0,-1,0,+1};

inline bool in(int i,int j){
    return (0<=i&&i<n&&0<=j&&j<m);
}


binary exp 

ll binpow(ll a,ll b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

ceil 

ll ceil2(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1)/b + 1;
}

COMBINATORICS TEMPLATE 

const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

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
*/

/*void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}*/

void solve()
{
    char grid[8][8];

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(grid[i][j]=='k')
            {
                if(i-2>=0&&j+1<8)
                {
                    if(grid[i-2][j+1]!='k')
                    {
                        grid[i-2][j+1]='n';
                    }
                }
                if(i+2<8&&j+1<8)
                {
                    if(grid[i+2][j+1]!='k')
                    {
                        grid[i+2][j+1]='n';
                    }
                }
                if(i+2<8&&j-1>=0)
                {
                    if(grid[i+2][j-1]!='k')
                    {
                        grid[i+2][j-1]='n';
                    }
                }
                if(i-2>=0&&j-1>=0)
                {
                    if(grid[i-2][j-1]!='k')
                    {
                        grid[i-2][j-1]='n';
                    }
                }
                if(i-1>=0&&j+2<8)
                {
                    if(grid[i-1][j+2]!='k')
                    {
                        grid[i-1][j+2]='n';
                    }
                    
                }
                if(i+1<8&&j+2<8)
                {
                    if(grid[i+1][j+2]!='k')
                    {
                        grid[i+1][j+2]='n';
                    }
                    
                }
                if(i+1<8&&j-2>=0)
                {
                    if(grid[i+1][j-2]!='k')
                    {
                        grid[i+1][j-2]='n';
                    }
                    
                }
                if(i-1>=0&&j-2>=0)
                {
                    if(grid[i-1][j-2]!='k')
                    {
                        grid[i-1][j-2]='n';
                    }
                }
            }
        }
    }
    /*cout << endl;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout << grid[i][j] ;
        }
        cout << endl;
    }*/

    int valid = 0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(grid[i][j]=='.')
            {
                //cout << "k" << endl;
                bool ok = true;
                int temp_x = j;
                int temp_y = i;

                while(temp_x<8&&temp_y<8)    //going south east
                {
                    if(grid[temp_y][temp_x]=='k')
                    {
                        //cout << temp_y << " " << temp_x << " this err" << endl; 
                        ok = false;
                        break;
                    }
                    //cout << temp_y << " " << temp_x << endl;
                    ++temp_x;
                    ++temp_y;
                }

                temp_x = j;
                temp_y = i;

                while(temp_x<8&&temp_y>=0)   // going north east
                {
                    if(grid[temp_y][temp_x]=='k')
                    {
                        //cout << temp_x << " " << temp_y << " err" << endl; 
                        ok = false;
                        break;
                    }
                    ++temp_x;
                    --temp_y;
                }

                temp_x = j;
                temp_y = i;

                while(temp_x>=0&&temp_y>=0)
                {
                    if(grid[temp_y][temp_x]=='k')
                    {
                        //cout << temp_x << " " << temp_y << " err" << endl; 
                        ok=false;
                        break;
                    }
                    --temp_x;
                    --temp_y;
                }

                temp_x = j;
                temp_y = i;

                while(temp_x>=0&&temp_y<8)
                {
                    if(grid[temp_y][temp_x]=='k')
                    {
                        //cout << temp_x << " " << temp_y << " err" << endl; 
                        ok=false;
                        break;
                    }
                    --temp_x;
                    ++temp_y;
                }

                /*if(!ok)
                {
                    cout << i << " " << j << endl;
                }*/

                if(ok)
                {
                    ++valid;
                }
            }
        }
    }

    cout << valid << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    //setIO("problemname");

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}