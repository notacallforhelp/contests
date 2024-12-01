#include <bits/stdc++.h>

using namespace std;

int ask(string t)
{
    cout << "? "<<t << endl;
    int res;
    cin>>res;
    return res;
}

void result(string t)
{
    cout << "! " << t << endl;
}

void solve()
{   
    int n; scanf("%d",&n);

    string k;

    while(k.size()<n)
    {
        if(ask(k+"0"))
        {
            k.push_back('0');
        }
        else if(ask(k+"1"))
        {
            k.push_back('1');
        }
        else
        {
            break;
        }
    }

    while(k.size()<n)
    {
        if(ask("0"+k))
        {
            k = "0" + k;
        }
        else
        {
            k = "1" + k;
        }
    }

    result(k);

}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        solve();
    }
}