#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

bool IsWithinBound(const int n, const int m, const int x, const int y)
{
    return (0 <= x) && (x < n)
        && (0 <= y) && (y < m);
}

int CalculateSafeSection(vector<vector<int>> grid, queue<PII> que)
{
    const int n = grid.size();
    const int m = grid[0].size();
    const vector<PII> dirs = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

    while (!que.empty())
    {
        PII curr = que.front(); que.pop();

        for (auto& dir : dirs)
        {
            int x = curr.first + dir.first;
            int y = curr.second + dir.second;

            if (!IsWithinBound(n, m, x, y)) continue;
            if (grid[x][y] > 0) continue;

            grid[x][y] = 2;
            que.push({ x, y });
        }
    }

    int result = 0;
    for (auto& row : grid)
    {
        for (auto& it : row)
        {
            if (it == 0)
                result++;
        }
    }

    return result;
}

int BackTracking(vector<vector<int>>& grid, const vector<PII>& empArray, queue<PII>& que, int index, int walls)
{
    if (walls == 3)
    {
        return CalculateSafeSection(grid, que);
    }

    int result = 0;
    for (int i = index; i < empArray.size(); i++)
    {
        int x = empArray[i].first;
        int y = empArray[i].second;

        if (grid[x][y] == 0)
        {
            grid[x][y] = 1;
            result = max(result, BackTracking(grid, empArray, que, i + 1, walls + 1));
            grid[x][y] = 0;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<PII> empArray;
    queue<PII> que;
    empArray.reserve(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 0)
                empArray.push_back({ i, j });
            else if (grid[i][j] == 2)
                que.push({ i, j });
        }
    }

    cout << BackTracking(grid, empArray, que, 0, 0);

    return 0;
}