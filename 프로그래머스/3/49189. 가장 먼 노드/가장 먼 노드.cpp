#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

#define INF 1000000

using namespace std;
//다익스트라 구현
int Dijkstra(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>> pQue;
    
    dist[1] = 0;
    pQue.push({dist[1], 1});
    while (!pQue.empty())
    {
        auto curr = pQue.top();
        pQue.pop();
        
        int d = curr.first;
        int v = curr.second;
        
        if (d > dist[v])
            continue;
        
        d += 1;
        for (int next : graph[v])
        {
            if (dist[next] <= d)
                continue;
            dist[next] = d;
            pQue.push({d, next});
        }
    }
    
    dist[0] = -1;
    sort(dist.begin(), dist.end(), std::greater<int>());
    
    int m = dist[0];
    int count = 0;
    for (int i : dist)
    {
        if (i == m)
        {
            count++;
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> edge) 
{
    vector<vector<int>> graph(n + 1);
    for (auto it : edge)
    {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    
    
    
    int answer = Dijkstra(graph);
    return answer;
}