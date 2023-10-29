#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

struct GridInfo
{
    PII coord;
    bool hasWallPass;
};

bool IsWithinBound(const int x, const int y, const int n, const int m)
{
    bool xBoundCheck = (0 <= x) && (x < n);
    bool yBoundCheck = (0 <= y) && (y < m);

    return xBoundCheck && yBoundCheck;
}

vector<vector<int>> InitializeGrid(const int n, const int m)
{
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = static_cast<int>(ch - '0');
        }
    }

    return grid;
}

int BFS(vector<vector<int>>& grid, const int n, const int m)
{
    const PII start = { 0, 0 };
    const PII goal = { n - 1, m - 1 };
    const vector<PII> dir = { {1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    queue<GridInfo> que;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));

    que.push({ start, true });
    dist[start.first][start.second][1] = 1;

    while (!que.empty())
    {
        auto currInfo = que.front(); que.pop();
        PII curr = currInfo.coord;
        bool hasWallPass = currInfo.hasWallPass;
        int currCount = dist[curr.first][curr.second][hasWallPass];

        if (curr == goal)
        {
            return currCount;
        }

        for (auto& it : dir)
        {
            int x = curr.first + it.first;
            int y = curr.second + it.second;

            if (!IsWithinBound(x, y, n, m)) continue;
            if (!hasWallPass && grid[x][y] == 1) continue;
            if (dist[x][y][hasWallPass] > 0) continue;

            GridInfo next = { {x, y}, hasWallPass };
            if (grid[x][y] == 1)
            {
                next.hasWallPass = false;
            }

            que.push(next);
            dist[x][y][next.hasWallPass] = currCount + 1;
        }

    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid = InitializeGrid(n, m);

    cout << BFS(grid, n, m);

    return 0;
}