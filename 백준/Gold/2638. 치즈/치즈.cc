#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;
const vector<PII> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int BFS(const int n, const int m, vector<vector<int>>& grid)
{
    queue<PII> que;
    vector<vector<int>> visitCnt(n, vector<int>(m, 0));
    vector<PII> meltCheeses; meltCheeses.reserve(n * m);

    que.push({ 0, 0 });
    visitCnt[0][0]++;

    while (!que.empty())
    {
        auto curr = que.front(); que.pop();

        for (auto dir : dirs)
        {
            int nx = curr.first + dir.first;
            int ny = curr.second + dir.second;

            bool isWithin = (0 <= nx) && (nx < n) && (0 <= ny) && (ny < m);
            if (!isWithin) continue;

            if (grid[nx][ny] == 0)
            {
                if (visitCnt[nx][ny] == 0)
                {
                    que.push({ nx, ny });
                }
            }
            else
            {
                if (visitCnt[nx][ny] == 1)
                {
                    meltCheeses.push_back({ nx, ny });
                }
            }

            visitCnt[nx][ny]++;
        }
    }

    int meltedCheeseCnt = meltCheeses.size();
    for (auto& cheese : meltCheeses)
    {
        grid[cheese.first][cheese.second] = 0;
    }
    return meltedCheeseCnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    int cheeses = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                cheeses++;
            }
        }
    }

    int result = 0;
    while (cheeses)
    {
        cheeses -= BFS(n, m, grid);
        result++;
    }

    cout << result;

    return 0;
}