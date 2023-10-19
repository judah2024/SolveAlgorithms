#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Pii = pair<int, int>;

void Dijkstra(const vector<vector<Pii>>& graph, const int start)
{
    const int inf = 9e8;

    vector<int> dist(graph.size(), inf);
    priority_queue<Pii, vector<Pii>, greater<Pii>> pQue;

    dist[start] = 0;
    pQue.push({ dist[start], start });

    while (!pQue.empty())
    {
        auto curr = pQue.top(); pQue.pop();
        int uDist = curr.first;
        int u = curr.second;

        if (dist[u] != uDist) continue;

        for (auto& it : graph[u])
        {
            int w = it.first;
            int v = it.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pQue.push({ dist[v], v });
            }
        }
    }


    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] == inf)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int V, E, start;
    cin >> V >> E >> start;

    vector<vector<Pii>> graph(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({ w, v });
    }

    Dijkstra(graph, start);

    return 0;
}