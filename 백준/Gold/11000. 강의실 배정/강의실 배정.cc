#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> timeTable(n);

    int s, e;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        timeTable[i] = { s, e };
    }
    sort(timeTable.begin(), timeTable.end());

    priority_queue<int, vector<int>, greater<int>> pQue;
    for (int i = 0; i < n; i++)
    {
        s = timeTable[i][0];
        e = timeTable[i][1];

        pQue.push(e);
        if (pQue.top() <= s)
        {
            pQue.pop();
        }
    }

    cout << pQue.size();

    return 0;
}