#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k , s;
    cin >> n >> k >> s;
    /*k = n*/
    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    vector<int> B(n);

    for(int i=0;i<n;i++)
    {
        B[i]=A[n-1-i];
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;

    int mini2 = INT_MAX;
    int maxi2 = INT_MIN;
    int output = 0;
    int output2 = 0;

    for(int i=0;i<n;i=i+s)
    {
        maxi = INT_MIN;
        mini = INT_MAX;

        maxi2 = INT_MIN;
        mini2 = INT_MAX;
        for(int j=0;j<s;j++)
        {
            if(i+j>=n)
            {
                break;
            }
            maxi=max(maxi,A[j+i]);
            mini=min(mini,A[j+i]);

            maxi2 = max(maxi2,B[j+i]);
            mini2 = min(mini2,B[i+j]);
        }
        if(mini!=INT_MAX&&maxi!=INT_MIN)
        {
            output = max(maxi-mini,output);
        }
        if(mini2!=INT_MAX&&maxi2!=INT_MIN)
        {
            output2 = max(maxi2-mini2,output2);
        }
    }
    /*int final = INT_MAX;
    for(int i=0;i<B.size();i++)
    {
        final = min(final,B[i]);
    }*/
    cout << min(output,output2) << endl;
}