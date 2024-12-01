#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;

    int minusone=0;
    int mini = INT_MAX;

    int A[N];

    for(int i=0;i<N;i++)
    {
        cin >> A[i];

        if(A[i]<K)
        {
            ++minusone;
        }
        else
        {
            mini = min(mini,A[i]%K);
        }
    }

    if(minusone==N)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mini << endl;
    }
}