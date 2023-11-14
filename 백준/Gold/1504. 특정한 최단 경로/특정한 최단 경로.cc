#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;

const int inf = 5e8;

vector<vector<PII>> InitializeGraph(const int n, const int e)
{
    vector<vector<PII>> graph(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v, e;
        cin >> u >> v >> e;
        graph[u].push_back({ v, e });
        graph[v].push_back({ u, e });
    }
    return graph;
}

vector<int> Dijkstra(const int n, const vector<vector<PII>>& graph, const int start)
{
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

        for (auto& near : graph[u])
        {
            int v = near.first;
            int w = near.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pQue.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int CalculateMinDistance(const int n, const vector<vector<PII>>& graph, const int u, const int v)
{
    const int start = 1;

    vector<int> uDist = Dijkstra(n, graph, u);
    vector<int> vDist = Dijkstra(n, graph, v);
    
    int distUV = uDist[1] + uDist[v] + vDist[n];
    int distVU = vDist[1] + vDist[u] + uDist[n];
    distUV = (distUV < inf ? distUV : inf);
    distVU = (distVU < inf ? distVU : inf);

    return min(distUV, distVU);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    vector<vector<PII>> graph = InitializeGraph(n, e);

    int u, v;
    cin >> u >> v;

    int result = CalculateMinDistance(n, graph, u, v);
    cout << (result == inf ? -1 : result);

    return 0;
}