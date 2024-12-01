#include <iostream>

using namespace std;

typedef long long int ll;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        string s; cin>>s;
        ll output = 0;

        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case 'G':
                    output += 3;
                    break;
                case 'S':
                    output += 2;
                    break;
                case 'B':
                    output +=1;
                    break;
                default:
                    break;
            }
        }
        cout << output << endl;
    }

    return 0;
}