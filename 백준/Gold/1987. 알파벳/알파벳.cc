#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using PII = pair<int, int>;

const vector<PII> dir = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int DFS(const int r, const int c,const vector<vector<char>>& grid, const PII& curr, vector<bool>& hasAlready)
{
    int dist = 0;
    for (auto& it : dir)
    {
        int x = curr.first + it.first;
        int y = curr.second + it.second;

        if ((0 <= x) && (x < r)
         && (0 <= y) && (y < c))
        {
            const char alphaIndex = grid[x][y] - 'A';
            if (hasAlready[alphaIndex]) continue;

            hasAlready[alphaIndex] = true;
            dist = max(dist, DFS(r, c, grid, { x, y }, hasAlready));
            hasAlready[alphaIndex] = false;
        }
    }
    return dist + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    for (auto& row : grid)
    {
        for (auto& it : row)
        {
            cin >> it;
        }
    }

    vector<bool> hasAlready('Z' - 'A' + 1, false);
    hasAlready[grid[0][0] - 'A'] = true;
    cout << DFS(r, c, grid, {0, 0}, hasAlready);

    return 0;
}