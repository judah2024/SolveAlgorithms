#include <iostream>
#include <vector>

using namespace std;

long long SumRange(const vector<vector<long long>>& nTable, const int x1, const int y1, const int x2, const int y2)
{
    return nTable[x2][y2] + nTable[x1][y1] - nTable[x1][y2] - nTable[x2][y1];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    long long n, m;
    vector<vector<long long>> nTable;

    cin >> n >> m;
    nTable.resize(n + 1, vector<long long>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nTable[i][j];
            nTable[i][j] += (nTable[i - 1][j] + nTable[i][j - 1]);
            nTable[i][j] -= nTable[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << SumRange(nTable, x1 - 1, y1 - 1, x2, y2) << "\n";
    }

    return 0;
}