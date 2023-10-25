#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;

vector<int> Dijkstra(const vector<vector<PII>>& graph, const int goal)
{
    const int inf = 1e9;
    const int n = graph.size() - 1;

    vector<int> dist(n + 1, inf);
    priority_queue<PII, vector<PII>, greater<PII>> pQue;

    dist[goal] = 0;
    pQue.push({ dist[goal] , goal });

    while (!pQue.empty())
    {
        PII curr = pQue.top(); pQue.pop();
        int currTown = curr.second;

        if (curr.first != dist[currTown]) continue;

        for (auto& next : graph[currTown])
        {
            int nextTown = next.first;
            int nextDist = next.second;

            if (dist[nextTown] > dist[currTown] + nextDist)
            {
                dist[nextTown] = dist[currTown] + nextDist;
                pQue.push({ dist[nextTown] , nextTown });
            }

        }
    }

    return dist;
}

int FindMaxDist(const vector<int>& dist, const vector<int>& revDist)
{
    const int n = dist.size() - 1;
    int maxDist = dist[1] + revDist[1];

    for (int i = 2; i <= n; i++)
    {
        maxDist = max(maxDist, dist[i] + revDist[i]);
    }

    return maxDist;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<PII>> graph(n + 1);
    vector<vector<PII>> revGraph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (graph[u].empty())
        {
            graph[u].reserve(n);
        }

        graph[u].push_back({ v, w });

        if (revGraph[v].empty())
        {
            revGraph[v].reserve(n);
        }
        revGraph[v].push_back({ u, w });
    }

    vector<int> dist = Dijkstra(graph, x);
    vector<int> revDist = Dijkstra(revGraph, x);

    cout << FindMaxDist(dist, revDist);

    return 0;
}