#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s; 
    cin >> s;
    char digit; cin>>digit;
    reverse(s.begin(), s.end());
    
    size_t pos = s.find(digit);
    if (pos != string::npos) {
        s.erase(pos, 1);
    }
    reverse(s.begin(),s.end());

    cout << s << endl;
}