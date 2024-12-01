#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a;
    cin>>a;

    if(a<=100)
    {
        cout << "NO\n";
        return;
    }

    int temp = a;
    vector<int> num;

    while(temp)
    {
        num.push_back(temp%10);
        temp = temp/10;
    }

    reverse(num.begin(),num.end());

    if(num[0]!=1||num[1]!=0||num[2]==0)
    {
        cout << "NO\n";
        return;
    }

    int exp = 0;
    int power = 1;

    for(int i=num.size()-1;i>=2;i--)
    {
        exp = exp + num[i]*power;
        power *= 10;
    }

    if(exp<2)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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