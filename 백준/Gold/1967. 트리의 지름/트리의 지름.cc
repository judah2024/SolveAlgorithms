#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;

PII DFSRaidus(const vector<vector<PII>>& graph, const int root)
{
    priority_queue<int> lengthQue;
    int distance = 0;

    lengthQue.push(0);
    lengthQue.push(0);

    for (auto& it : graph[root])
    {
        auto childLengthInfo = DFSRaidus(graph, it.first);

        distance = max(distance, childLengthInfo.first);
        lengthQue.push(childLengthInfo.second + it.second);
    }

    int maxLength = lengthQue.top(); lengthQue.pop();
    distance = max(distance, maxLength + lengthQue.top());

    return { distance, maxLength };
}

int CalculateRadius(const vector<vector<PII>>& graph)
{
    PII result = DFSRaidus(graph, 1);

    return result.first;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<PII>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({ v, w });
    }

    cout << CalculateRadius(graph);

    return 0;
}