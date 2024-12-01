#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;

    vector<int> A(n);

    //IF ALREADY SORTED THEN NO NEED
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    for(int i=n-1;i>=0;i--)
    {
        if(A[i]>=10)
        {
            int Rval = A[i]%10;
            int Lval = A[i]/10;
            /*cout << Lval << " " << Rval<<endl;*/
            if(Lval>Rval)
            {
                continue;
            }
            bool ok1=true,ok2=true;
            for(int j=i-1;j>=1;j--)
            {
                if(A[j]/10!=0)
                {
                    int Rval2=A[j]%10;
                    int Lval2=A[j]/10;
                }
                if(j==i-1)
                {

                }
            }
            for(int j=i+1;j<n;j++)
            {
                if(A[j]/10==0&&j-i!=1)
                {
                    break;
                }
                if(j==i+1&&A[j]<Rval)
                {
                    ok2=false;
                }
                if(j!=i+1&&A[j]<A[j-1])
                {
                    /*cout << "A[j] ="<<A[j]<<endl;*/
                    ok2=false;
                }
            }
            if(ok1==true&&ok2==true)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    
    
    
    //IF ARRAY IS SORTED, IT GETS HANDLED BY THIS
    vector<int> C=A;
    sort(A.begin(),A.end());
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=C[i])
        {
            break;
        }
        else
        {
            ++count;
        }
    }
    if(count==n)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
    

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