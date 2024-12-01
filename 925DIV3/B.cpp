#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        ll sum = 0;

        vector<int> A(n);


        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            sum += A[i];
        }

        int eleneed = sum/n;
        int count = 0;
        if(A[0]<eleneed)
        {
            cout << "NO\n";
            continue;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(A[i]>eleneed)
            {
                cout << "NO\n";
                break;
            }
            else if(A[i]<eleneed)
            {
                int sumneed = eleneed-A[i];
                int j = i-1;
                while(j>=0)
                {
                    if(A[j]-sumneed>0)
                    {
                        A[j]=A[j]-sumneed;
                        A[i]=eleneed;
                        break;
                    }
                    j--;
                }
            }
            if(A[i]!=eleneed)
            {
                cout << "NO\n";
                break;
            }
            ++count;
        }
        if(count ==n)
        {
            cout << "YES\n";
        }
    }
}