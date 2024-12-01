#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s1;
    int s2;
    cin >> s1 >> s2;

    vector<int> v1;
    vector<int> v2;
    int val;
    for(int i=0;i<s1;i++)
    {
        cin >> val;
        v1.push_back(val);
    }
    for(int i=0;i<s2;i++)
    {
        cin >> val;
        v2.push_back(val);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    int k=0,p=0;
    int ct=0;

    /*for(int i=0;i<s1;i++)
    {
        cout << v1[i]<< " ";
    }*/

    while(p<s2&&k<s1)
    {
        if(v2[p]==v1[k])
        {
            ++ct;
            ++p;
            ++k;
        }
        else
        {
            ++k;
        }
    }

    /*cout << ct << endl;*/

    if(ct==s2)
    {
        cout << 1<<endl;
    }
    else
    {
        cout << 0 << endl;
    }
}