#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;
using Row = vector<int>;

istream& operator>> (istream& is, Matrix& matrix)
{
    for (auto& row : matrix)
    {
        for (auto& it : row)
        {
            is >> it;
        }
    }
    return is;
}

ostream& operator<< (ostream& os, const Matrix& matrix)
{
    const int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            os << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return os;
}

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
    cin >> matrix;

    cout << PowMatrix(matrix, b);

    return 0;
}