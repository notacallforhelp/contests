#include <bits/stdc++.h>

using namespace std;

int main()
{
    string k; cin>>k;

    char digit; cin>>digit;

    for(int i=0;i<k.size()-1;i++)
    {
        if(k[i]==digit&&k[i+1]>k[i])
        {
            k.erase(i,1);
            cout << k << endl;
            return 0;
        }
    }

    reverse(k.begin(),k.end());
    k.erase(k.find(digit),1);
    reverse(k.begin(),k.end());
    cout << k << endl;
    return 0;
}