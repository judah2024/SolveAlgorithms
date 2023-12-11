#include <string>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e7;

vector<int> Dijkstra(const int n, const vector<vector<int>>& graph, const int start)
{
    vector<int> dist(n + 1, inf);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pQue;

    dist[start] = 0;
    pQue.push({ dist[start], start});

    while (!pQue.empty())
    {
        auto currInfo = pQue.top(); pQue.pop();
        int currDist = currInfo[0], curr = currInfo[1];

        if (dist[curr] != currDist) continue;

        for (auto& next : graph[curr])
        {
            if (dist[next] > dist[curr] + 1)
            {
                dist[next] = dist[curr] + 1;
                pQue.push({ dist[next], next });
            }
        }

    }
    return dist;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {

    vector<vector<int>> graph(n + 1);
    for (auto road : roads)
    {
        int u = road[0], v = road[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist = Dijkstra(n, graph, destination);
    vector<int> answer;
    for (auto& start : sources)
    {
        answer.push_back(dist[start] == inf ? -1 : dist[start]);
    }

    return answer;
}
