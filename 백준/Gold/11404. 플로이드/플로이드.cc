#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> StoreRouteGraph(const int n, const int m)
{
    constexpr int inf = 5e8;
    vector<vector<int>> routeGraph(n + 1, vector<int>(n + 1, inf));

    for (int i = 0; i <= n; i++)
    {
        routeGraph[i][i] = 0;
    }

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        routeGraph[u][v] = min(routeGraph[u][v], w);
    }

    return routeGraph;
}

void Floyd(vector<vector<int>>& routeGraph, const int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (routeGraph[u][v] > routeGraph[u][k] + routeGraph[k][v])
                {
                    routeGraph[u][v] = routeGraph[u][k] + routeGraph[k][v];
                }
            }
        }
    }
}

void PrintRouteCost(vector<vector<int>>& routeGraph, const int n)
{
    constexpr int inf = 5e8;

    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (routeGraph[u][v] == inf)
            {
                routeGraph[u][v] = 0;
            }

            cout << routeGraph[u][v] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> routeGraph = StoreRouteGraph(n, m);
    Floyd(routeGraph, n);
    PrintRouteCost(routeGraph, n);

    return 0;
}