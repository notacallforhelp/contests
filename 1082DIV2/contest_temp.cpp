#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef long long ll;
typedef long double ld;

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);

    map<int,int> M;

    vector<int> A = {5,7,9,16,25,69};


    // we're saying that in the map M, A[i] is present, if M[A[i]]=1 then present, else if M[A[i]]=0 then not present
    for(int i=0;i<6;i++)
    {
        M[A[i]]=1;
    }

    // check if 54 is active or not

    cout << M[54] << "\n"; // 0 then not present, else present

    cout << M[9] << "\n"; 

    //

    return 0;
}