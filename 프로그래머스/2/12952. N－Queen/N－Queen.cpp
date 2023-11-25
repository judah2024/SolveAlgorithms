#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPlacedQueen(vector<int>& queens, vector<int>& isVisitedHorizontal, const int count, const int k)
{
    if (isVisitedHorizontal[k]) return false;

    for (int i = 0; i < queens.size(); i++)
    {
        int gapH = abs(count - i);
        int gapV = abs(k - queens[i]);

        if (gapH == gapV) return false;
    }

    return true;
}

int BTQueen(vector<int>& queens, vector<int>& isVisitedHorizontal, const int n, const int count)
{
    if (count == n)
    {
        return 1;
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPlacedQueen(queens, isVisitedHorizontal, count, i))
        {
            queens.push_back(i);
            isVisitedHorizontal[i] = true;

            total += BTQueen(queens, isVisitedHorizontal, n, count + 1);

            isVisitedHorizontal[i] = false;
            queens.pop_back();
        }
    }

    return total;
}

int CalculateQueenArrangement(const int n)
{
    vector<int> queens;
    vector<int> isVisitedHorizontal(n, false);

    queens.reserve(n);

    return BTQueen(queens, isVisitedHorizontal, n, 0);
}

int solution(int n) {
    return CalculateQueenArrangement(n);
}