#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

const int mStep = 100;
const int sCondition = 3 * mStep + 1;
const int eCondition = 12 * mStep + 1;

int CalculateMinFlowerCount(const vector<PII>& flowers)
{
    const int n = flowers.size();

    int e = sCondition, flowerCount = 0, idx = 0;
    while (e < eCondition)
    {
        int nextE = e;
        for (int i = idx; i < n; i++)
        {
            if (flowers[i].first <= e)
            {
                if (nextE < flowers[i].second)
                {
                    nextE = flowers[i].second;
                    idx = i + 1;
                }
            }
            else
            {
                break;
            }
        }

        if (nextE == e)
        {
            flowerCount = 0;
            break;
        }
        flowerCount++;
        e = nextE;
    }

    return flowerCount;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<PII> flowers;
    flowers.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int sM, sD, eM, eD;
        cin >> sM >> sD >> eM >> eD;
        int s = sM * mStep + sD;
        int e = eM * mStep + eD;

        if (e < sCondition) continue;
        if (s >= eCondition) continue;

        flowers.push_back({ s, e });
    }
    sort(flowers.begin(), flowers.end());

    cout << CalculateMinFlowerCount(flowers);

    return 0;
}