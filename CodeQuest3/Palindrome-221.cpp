#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;

    cin >> S;

    int k = S.size();

    for(int i=0;i<k/2;i++)
    {
        if(S[i]!=S[k-1-i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}