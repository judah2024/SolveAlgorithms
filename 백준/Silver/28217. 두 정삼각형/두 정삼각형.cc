#include <iostream>
#include <vector>

using namespace std;

using Triangle = vector<vector<int>>;

void InitTriangle(Triangle& triangle)
{
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }
}

void RotateTriangle(Triangle& origin, Triangle& outTriangle)
{
    const int n = origin.size();

    for (int i = 0; i < n; i++)
    {
        int y = n - i - 1;
        for (int j = 0; j <= i; j++)
        {
            int x = j + y;
            outTriangle[i][j] = origin[x][y];
        }
    }
}

vector<int> CompareTriangle(Triangle& origin, Triangle& compare)
{
    const int n = origin.size();

    vector<int> total(2, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (origin[i][j] != compare[i][j])
            {
                total[0]++;
            }

            if (origin[n - j - 1][n - i - 1] != compare[i][j])
            {
                total[1]++;
            }
        }
    }

    return total;
}

int main()
{
    const int tri = 3;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<Triangle> triangles(tri, Triangle(n, vector<int>(n, 0)));
    Triangle compareTriangle(n, vector<int>(n, 0));

    InitTriangle(triangles[0]);
    InitTriangle(compareTriangle);

    for (int i = 1; i < tri; i++)
    {
        RotateTriangle(triangles[i - 1], triangles[i]);
    }

    vector<vector<int>> answers(tri, vector<int>(2, 0));
    for (int i = 0; i < tri; i++)
    {
        answers[i] = CompareTriangle(triangles[i], compareTriangle);
    }

    int minScore = answers[0][0];
    for (auto& row : answers)
    {
        for (auto& it : row)
        {
            minScore = min(minScore, it);
        }
    }

    cout << minScore;

    return 0;
}