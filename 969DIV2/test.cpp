#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i=1;

    while(i<1000)
    {
        cout << __gcd(i,i+1)+__gcd(i+1,i+2)+__gcd(i+2,i)<<endl;
        i=i+4;
    }
}