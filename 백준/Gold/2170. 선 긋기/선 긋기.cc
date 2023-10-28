#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<PII> lines(n);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        lines[i] = { s, e };
    }
    sort(lines.begin(), lines.end());

    long long length = 0;
    int lineEnd = lines[0].first;
    for (auto& line : lines)
    {
        int s = line.first;
        int e = line.second;

        if (lineEnd < s)
        {
            length += e - s;
        }
        else
        {
            length += max(0, e - lineEnd);
        }

        lineEnd = max(e, lineEnd);
    }

    cout << length;

    return 0;
}