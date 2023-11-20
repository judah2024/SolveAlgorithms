#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& sales, const vector<vector<int>>& graph, vector<vector<int>>& dp, const int head)
{
    if (graph[head].empty())
    {
        return;
    }

    for (auto& mem : graph[head])
    {
        DFS(sales, graph, dp, mem);
    }

    int min0 = 0;
    for (auto& mem : graph[head])
    {
        min0 += min(dp[mem][0], dp[mem][1]);
    }

    int min1 = 1e9;
    for (auto& mem : graph[head])
    {
        int minMem = min(dp[mem][0], dp[mem][1]);
        min1 = min(min1, min0 - minMem + dp[mem][0]);
    }

    dp[head][0] += min0;
    dp[head][1] += min1;

}

int solution(vector<int> sales, vector<vector<int>> links) {
    const int n = sales.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = sales[i];
    }

    vector<vector<int>> graph(n + 1);
    for (auto& link : links)
    {
        graph[link[0]].push_back(link[1]);
    }

    DFS(sales, graph, dp, 1);

    int answer = min(dp[1][0], dp[1][1]);
    return answer;
}
