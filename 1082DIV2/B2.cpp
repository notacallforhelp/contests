#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long long ll;
typedef long double ld;

void solve()
{   
   int n; cin>>n;
   string s; cin>>s;

   if(n%2!=0)
   {
        if(s[0]=='?')
        {
            s[0]='a';
        }
   }

   if(n%2==0)
   {
        if(s[0]=='?') // ?
        {
            if(s[1]!='?') // ? a or ? b
            {
                if(s[1]=='a') s[0]='b';
                if(s[1]=='b') s[0]='a';
            }
            else // ? ?
            {
                if(n==2) // ? ?
                {
                    cout << "YES\n"; return;
                }
                if(s[2]!='?')  // ? ? a  or ? ? b
                {
                    if(s[2]==s[3])
                    {
                        if(s[2]=='a')  // a b a 
                        {
                            s[1]='b';
                            s[0]='a';
                        }
                        else  // b a b 
                        {
                            s[1]='a';
                            s[0]='b';
                        }
                    }
                    else // ? ? a b or ? ? b a
                    {
                        s[1]='a';
                        s[0]='b';
                    }
                }
                else // ? ? ?
                {
                    if(s[2]=='a') // aba
                    {
                        s[1]='b';
                        s[0]='a';
                    }
                    else // bab
                    {
                        s[1]='a';
                        s[0]='b';
                    }
                }
            }
        }
   }

   //cout << s << endl;

   if(n%2!=0)
   {
        if(s[0]=='b')
        {
            cout << "NO\n"; return;
        }
   }

   if(n%2==0)
   {
        if(s[0]==s[1])
        {
            cout << "NO\n"; return;
        }
   }

   int score = 0;

   for(int i=0;i<n;i++)
   {
        if(s[i]=='?')
        {
            if(score==2)
            {
                s[i]='b';
            }
            else if(score==-2)
            {
                s[i]='a';
            }
            else if(i==n-1)
            {
                if(s[i-1]=='a') s[i]='b';
                if(s[i-1]=='b') s[i]='a';
            }
            else
            {
                if(s[i-1]!=s[i+1])
                {
                    s[i]=s[i-1];
                }
                else
                {
                    if(s[i-1]=='a') s[i]='b';
                    if(s[i-1]=='b') s[i]='a';
                }
            }
        }

        score += (s[i]=='a'?1:-1);
        if(score>2 || score<-2)
        {
            cout << "NO\n";
            return;
        }
   }
   
   //cout << s << endl;

   cout << "YES\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    int t; cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}