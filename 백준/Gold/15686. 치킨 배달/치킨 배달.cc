#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using PII = pair<int, int>;

vector<PII> chickens;
vector<PII> houses;
vector<int> nArray;
vector<bool> hasAlready;

const int inf = 1e9;

void InitializeCoords(const int n, const int m)
{
    chickens.reserve(13);
    houses.reserve(2 * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int building;
            cin >> building;
            if (building == 1)
            {
                houses.push_back({ i, j });
            }
            else if (building == 2)
            {
                chickens.push_back({ i, j });
            }
        }
    }

}

int CalculateDistance()
{
    int result = 0;
    for (int j = 0; j < houses.size(); j++)
    {
        int minDist = inf;
        for (auto& it : nArray)
        {
            int dist = abs(chickens[it].first - houses[j].first) + abs(chickens[it].second - houses[j].second);
            minDist = min(minDist, dist);
        }
        result += minDist;
    }
    return result;
}

int BackTracking_Chicken(const int m, const int index)
{
    if (nArray.size() == m)
    {
        return CalculateDistance();
    }

    int result = inf;
    for (int i = index; i < chickens.size(); i++)
    {
        if (hasAlready[i]) continue;

        nArray.push_back(i);
        hasAlready[i] = true;

        result = min(result, BackTracking_Chicken(m, i + 1));

        hasAlready[i] = false;
        nArray.pop_back();

    }

    return result;
}

int CalculateMinDistance(const int m)
{
    hasAlready.resize(chickens.size(), false);

    nArray.reserve(m);
    return BackTracking_Chicken(m, 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    InitializeCoords(n, m);

    cout << CalculateMinDistance(m);

    return 0;
}