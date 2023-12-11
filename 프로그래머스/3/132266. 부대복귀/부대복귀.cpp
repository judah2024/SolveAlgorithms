#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;
    vector<vector<int>> adj(100001);

    for (int i = 0; i < roads.size(); ++i)
    {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }

    for (int i = 0; i < sources.size(); ++i)
    {
        int d = -1;
        queue<pair<int, int>> que;
        vector<bool> isVisited(100001, false);

        isVisited[sources[i]] = true;
        que.push({ sources[i], 0 });
        while (!que.empty())
        {
            auto item = que.front();
            int road = item.first;
            int cnt = item.second;

            que.pop();

            if (road == destination)
            {
                d = cnt;

                break;
            }

            for (int j = 0; j < adj[road].size(); ++j)
            {
                int next = adj[road][j];
                if (!isVisited[next])
                {
                    isVisited[next] = true;
                    que.push({ next, cnt + 1 });
                }
            }
        }

        answer.push_back(d);
    }

    return answer;
}