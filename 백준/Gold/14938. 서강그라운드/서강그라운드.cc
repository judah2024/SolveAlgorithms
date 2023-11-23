#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

int Dijkstra(const int n, const int m, const vector<int>& itemCnt, const vector<vector<PII>>& graph, const int start)
{
    const int inf = 1e8;
    vector<int> dist(n + 1, inf);
    priority_queue<PII, vector<PII>, greater<PII>> pQue;

    dist[start] = 0;
    pQue.push({ dist[start], start });

    while (!pQue.empty())
    {
        auto curr = pQue.top(); pQue.pop();
        int uDist = curr.first;
        int u = curr.second;

        if (uDist != dist[u]) continue;

        for (auto& next : graph[u])
        {
            int v = next.first;
            int w = next.second;

            if (dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;

            if (dist[v] < m)
            {
                pQue.push({ dist[v], v });
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] <= m)
        {
            result += itemCnt[i];
        }
    }
    return result;
}

int CalculateOtaniableItemCount(const int n, const int m, const vector<int>& itemCnt, const vector<vector<PII>>& graph)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = max(result, Dijkstra(n, m, itemCnt, graph, i));
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> itemCnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> itemCnt[i];
    }

    vector<vector<PII>> graph(n + 1);
    for (int i = 0; i < r; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    cout << CalculateOtaniableItemCount(n, m, itemCnt, graph);

    return 0;
}