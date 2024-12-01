#include <bits/stdc++.h>

using namespace std;

const int m = 2e5+10;
int hsh[m];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        for(int i=0;i<m;i++)
        {
            hsh[i]=0;
        }

        int n;
        cin >> n;

        vector<int> A(n);

        for(int i=0;i<n;i++)
        {
            cin >> A[i];
            ++hsh[A[i]];
        }

        int maxfreqele;
        int maxfreq=0;

        vector<int> ele;

        for(int i=0;i<=n;i++)
        {
            if(hsh[i]>maxfreq)
            {
                maxfreqele=i;
                maxfreq=hsh[i];
            }
        }

        for(int i=0;i<=n;i++)
        {
            if(hsh[i]==maxfreq)
            {
                ele.push_back(i);
            }
        }
        int index = n+1;
        int chosen = -1;
        for(int &val:ele)
        {
            int l_index=n+2;
        
            for(int i=0,j=n-1;i<n;i++)
            {
                if(A[i]==val)
                {
                    l_index = i;
                    break;
                }
                else if(A[j]==val)
                {
                    l_index = n-1 -j;
                    break;
                }
            }
            if(l_index<index)
            {
                chosen = val;
                index = l_index;
            }
        }

        int left = n+1;
        int right = -1;

        for(int i=0;i<n;i++)
        {
            if(A[i]!=chosen)
            {
                if(i<left)
                {
                    left = i;
                }
                if(i>right)
                {
                    right = i;
                }
            }
        }
        if(left==n+1||right==-1)
        {
            cout<<"0\n";
        }
        else
        {
            cout << right -left +1 << endl;
        }

    }
}