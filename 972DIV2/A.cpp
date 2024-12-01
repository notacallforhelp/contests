#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    string k = "";

    char s[]={'a','e','i','o','u'};

    if(n<=5)
    {
        for(int i=0;i<n;i++)
        {
            k.push_back(s[i]);
        }
        cout << k << endl;
        return;
    } 

    int times = n/5;
    int rem = n%5;
    int fora;
    int fore;
    int fori;
    int foro;
    int foru;

    fora=fore=fori=foro=foru=times;

    if(rem)
    {
        ++fora;
        --rem;
    }

    for(int i=0;i<fora;i++)
    {
        k.push_back('a');
    }

    if(rem)
    {
        ++fore;
        --rem;
    }

    for(int i=0;i<fore;i++)
    {
        k.push_back('e');
    }

    if(rem)
    {
        ++fori;
        --rem;
    }

    for(int i=0;i<fori;i++)
    {
        k.push_back('i');
    }

    if(rem)
    {
        ++foro;
        --rem;
    }

    for(int i=0;i<foro;i++)
    {
        k.push_back('o');
    }

    if(rem)
    {
        ++foru;
        --rem;
    }

    for(int i=0;i<foru;i++)
    {
        k.push_back('u');
    }

    cout << k << endl;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}