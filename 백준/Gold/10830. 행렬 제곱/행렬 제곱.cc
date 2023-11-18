#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;
using Row = vector<int>;

Matrix operator* (const Matrix& lhs, const Matrix& rhs)
{
    const int n = lhs.size();
    Matrix newMatrix(n, Row(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (lhs[i][k] != 0 && rhs[k][j] != 0)
                    newMatrix[i][j] += lhs[i][k] * rhs[k][j];
            }
            newMatrix[i][j] %= 1000;
        }
    }
    return newMatrix;
}

Matrix PowMatrix(Matrix& matrix, unsigned long long b)
{
    const int n = matrix.size();
    Matrix result(n, Row(n));
    for (int i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }

    while (b > 0)
    {
        if (b & 1)
        {
            result = result * matrix;
        }

        matrix = matrix * matrix;
        b >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    unsigned long long  n, b;
    cin >> n >> b;

    Matrix matrix(n, Row(n));
    for (auto& row : matrix)
    {
        for (auto& it : row)
        {
            cin >> it;
        }
    }

    Matrix result = PowMatrix(matrix, b);
    for (auto& row : result)
    {
        for (auto& it : row)
        {
            cout << it << " ";
        }
        cout << "\n";
    }


    return 0;
}