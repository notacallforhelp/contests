#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    stack<int> S;

    cin >> n;

    vector<int> A(n);
    vector<int> NGE(n);

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }

    for(int i=0;i<n;i++)
    {
        while(!S.empty()&&A[i]>A[S.top()])
        {
            NGE[S.top()]=A[i];
            S.pop();
        }

        S.push(i);
    }

    while(!S.empty())
    {
        NGE[S.top()]=-1;
        S.pop();
    }

    for(int i=0;i<n;i++)
    {
        cout << A[i] << " " << NGE[i] << endl;
    }
}