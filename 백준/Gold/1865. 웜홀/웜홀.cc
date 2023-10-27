#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> InitializeGraph(const int n, const int m, const int w)
{
    vector<vector<int>> edges;
    edges.reserve(2 * m + w);
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({ s, e, t });
        edges.push_back({ e, s, t });
    }

    for (int i = 0; i < w; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({ s, e, -t });
    }
    
    return edges;
}

bool Bellman(const vector<vector<int>>& edges, const int n)
{
    const int inf = 1e9;

    vector<int> dist(n + 1, inf);
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        bool isChanged = false;
        for (auto& edge : edges)
        {
            int s = edge[0], e = edge[1], t = edge[2];

            if (dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
                isChanged = true;
            }
        }

        if (!isChanged)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int n, m, w;
        cin >> n >> m >> w;

        vector<vector<int>> edges = InitializeGraph(n, m, w);

        cout << (Bellman(edges, n) ? "YES" : "NO") << "\n";
    }

    return 0;
}