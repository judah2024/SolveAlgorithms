#include <vector>
#include <queue>

using namespace std;

const int inf = 1e7;

vector<int> BFS(const vector<vector<int>>& graph, int destination)
{
    vector<int> dist(graph.size(), inf);
    queue<int> que;
    
    dist[destination] = 0;
    que.push(destination);
    
    while(!que.empty())
    {
        auto curr = que.front(); que.pop();
        
        for (auto& next : graph[curr])
        {
            if (dist[next] > dist[curr] + 1)
            {
                dist[next] = dist[curr] + 1;
                que.push(next);
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

    vector<int> dist = BFS(graph, destination);
    vector<int> answer;
    for (auto& start : sources)
    {
        answer.push_back(dist[start] == inf ? -1 : dist[start]);
    }

    return answer;
}