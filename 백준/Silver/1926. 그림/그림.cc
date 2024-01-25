#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(const int n, const int m, vector<vector<int>>& grid, const pair<int, int>& start)
{
	const vector<pair<int, int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	queue<pair<int, int>> que;
	int area = 0;

	grid[start.first][start.second] = 0;
	que.push(start);

	while (!que.empty())
	{
		// 그림인 픽셀만 큐에 들어가므로 넓이값을 늘려준다.
		auto curr = que.front();
		que.pop();
		area++;

		for (auto& dir : dirs)
		{
			int x = curr.first + dir.first;
			int y = curr.second+ dir.second;

			// 유효한 주소 위치인지 확인후 픽셀의 값을 확인한다.
			// 픽셀값이 0이면 그림이 아니므로 무시한다.
			bool isInGrid = (0 <= x) && (x < n) && (0 <= y) && (y < m);
			if (!isInGrid) continue;
			if (grid[x][y] == 0) continue;

			grid[x][y] = 0;
			que.push({ x, y });
		}
	}
	return area;
}

vector<int> CalculateDrawInfo(const int n, const int m, vector<vector<int>>& grid)
{
	// 반환값
	int drawCnt = 0;
	int maxArea = 0;

	// 모든 픽셀을 확인하면서 아직 탐색하지 않은 그림이 있으면 BFS 실행
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (grid[x][y])
			{
				drawCnt++;
				maxArea = max(maxArea, BFS(n, m, grid, { x, y }));
			}
		}
	}

	return { drawCnt, maxArea };
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (auto& row : grid)
		for (auto& it : row)
			cin >> it;

	auto answer = CalculateDrawInfo(n, m, grid);
	cout << answer[0] << "\n"
		 << answer[1] << "\n";

	return 0;
}