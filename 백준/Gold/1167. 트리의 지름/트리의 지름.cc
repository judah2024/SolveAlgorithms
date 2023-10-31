#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using PII = pair<int, int>;

vector<vector<PII>> InitializeGraph(const int v)
{
    vector<vector<PII>> graph(v + 1);

    for (int i = 0; i < v; i++)
    {
        int s, e, w;
        cin >> s >> e;

        while (e != -1)
        {
            cin >> w;

            graph[s].push_back({ e, w });

            cin >> e;
        }
    }

    return graph;
}

PII DFS(const vector<vector<PII>>& graph, const int v, const int start)
{
    stack<PII> stk;
    vector<bool> isVisited(v + 1, false);

    stk.push({ start, 0 });
    isVisited[start] = true;

    PII farRoot = { 0, start };
    while (!stk.empty())
    {
        PII currInfo = stk.top(); stk.pop();
        int curr = currInfo.first;
        int dist = currInfo.second;
        
        bool isLeaf = true;

        for (auto& it : graph[curr])
        {
            int next = it.first;
            int w = it.second;

            if (isVisited[next]) continue;

            isLeaf = false;
            stk.push({ next, dist + w });
            isVisited[next] = true;
        }

        if (isLeaf)
        {
            farRoot = max(farRoot, { dist, curr });
        }
    }

    return farRoot;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int v;
    cin >> v;

    vector<vector<PII>> graph = InitializeGraph(v);

    PII rootInfo = DFS(graph, v, 1);
    int root = rootInfo.second;
    PII radiusInfo = DFS(graph, v, root);
    int radius = radiusInfo.first;

    cout << radius;


    return 0;
}