#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int size = s.size();

    for(int i=0;i<size/2;i++)
    {
        if(s[i]<s[size-1-i])
        {
            break;
        }
        else if(s[i]>s[size-1-i])
        {
            reverse(s.begin(), s.end());
            for(int i=size-1;i>=0;i--)
            {
                s.push_back(s[i]);
            }
            break;
        }
    }
    cout << s << endl;

}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
}