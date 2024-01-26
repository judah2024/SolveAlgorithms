#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

int BFS(const int n, const PII& start, const PII& end)
{
	const vector<PII> dirs = { { 2, 1 }, { 2, -1 }, { -2, 1 }, { -2, -1 }, { 1, 2 }, { 1, -2 }, { -1, 2 }, { -1, -2 } };

	vector<vector<bool>> isVisited(n, vector<bool>(n, false));
	queue<pair<PII, int>> que;

	isVisited[start.first][start.second] = true;
	que.push({ start, 0 });
	while (!que.empty())
	{
		auto currInfo = que.front();
		PII curr = currInfo.first;
		int moveCnt = currInfo.second;
		que.pop();

		if (curr == end) return moveCnt;

		moveCnt++;
		for (auto& dir : dirs)
		{
			int x = curr.first + dir.first;
			int y = curr.second + dir.second;

			bool isValidPos = (0 <= x) && (x < n) && (0 <= y) && (y < n);
			if (!isValidPos) continue;
			if (isVisited[x][y]) continue;

			isVisited[x][y] = true;
			que.push({ { x, y }, moveCnt });
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		PII start;
		PII end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		cout << BFS(n, start, end) << "\n";
	}

	return 0;
}