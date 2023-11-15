#include <iostream>
#include <vector>

#define MAX_LEN 20

using namespace std;
using PII = pair<int, int>;

char grid[MAX_LEN][MAX_LEN];
bool hasAlready['Z' - 'A' - 1];

const vector<PII> dir = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

bool IsWithinBound(const int r, const int c, const int x, const int y)
{
    return (0 <= x) && (x < r)
        && (0 <= y) && (y < c);
}

int DFS(const int r, const int c, const PII& curr)
{
    int result = 0;
    for (auto& it : dir)
    {
        int x = curr.first + it.first;
        int y = curr.second + it.second;

        if (!IsWithinBound(r, c, x, y)) continue;
        
        const char alphaIndex = grid[x][y] - 'A';
        if (hasAlready[alphaIndex]) continue;

        hasAlready[alphaIndex] = true;
        result = max(result, DFS(r, c, { x, y }));
        hasAlready[alphaIndex] = false;
    }
    return result + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    hasAlready[grid[0][0] - 'A'] = true;
    cout << DFS(r, c, { 0, 0 });

    return 0;
}