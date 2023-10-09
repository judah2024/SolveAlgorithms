#include <iostream>
#include <queue>

using namespace std;

int DFS(const long long& a, const long long& b)
{
    queue<vector<long long>> que;
    long long n, opCount;

    que.push({ a, 1 });
    while (!que.empty())
    {
        auto curr = que.front(); que.pop();
        n = curr[0];
        opCount = curr[1];

        if (n == b)
        {
            return opCount;
        }

        if (n < b)
        {
            que.push({ n * 2, opCount + 1 });
            que.push({ n * 10 + 1 , opCount + 1 });
        }
    }

    return -1;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << DFS(a, b) << "\n";

    return 0;
}
