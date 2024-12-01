#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(7);

    // Use a while loop to print elements of the queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}