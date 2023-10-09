#include <iostream>
#include <vector>

using namespace std;

const vector<vector<vector<int>>> tetris =
{
	{{0, 1}, {0, 1}, {1, -1}},	// T
	{{0, 1}, {0, 1}, {1, 0}},	// J
	{{0, 1}, {0, 1}, {-1, 0}},	// L
	{{0, 1}, {1, 0}, {0, -1}},	// O
	{{0, 1}, {0, 1}, {0, 1}},	// I
	{{0, 1}, {1, 0}, {0, 1}},	// S
	{{0, 1}, {-1, 0}, {0, 1}}	// Z
};

bool IsWithinBounds(const int& n, const int& m, const int& x, const int& y)
{
	bool xBoundCheck = (0 <= x) && (x < n);
	bool yBoundCheck = (0 <= y) && (y < m);
	return xBoundCheck && yBoundCheck;
}

vector<vector<int>> RotateBlock(const int& block, const int& rotation)
{
	vector<int> coord = { 0, 1 };
	vector<int> scale = { 1, 1 };
	auto& currBlock = tetris[block];

	if (rotation / 2 == 1)
	{
		scale[0] *= -1;
		scale[1] *= -1;
	}

	if (rotation % 2 == 1)
	{
		swap(coord[0], coord[1]);
		scale[1] *= -1;
	}

	vector<vector<int>> tetromino;
	tetromino.reserve(currBlock.size());
	for (auto& it : currBlock)
	{
		tetromino.push_back({ it[coord[0]] * scale[0], it[coord[1]] * scale[1] });
	}

	int zzzz = 0;

	return tetromino;
}

long long CalculateMaxScore(const vector<vector<int>>& board, const int& block, const int& rotation)
{
	if (block > 3 && rotation > 2)
	{
		return 0;
	}

	if (block == 3 && rotation > 1)
	{
		return 0;
	}

	int n = board.size(), m = board[0].size();
	vector<vector<int>> tetromino = RotateBlock(block, rotation);

	long long maxScore = 0, score = 0;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x = i; 
			y = j;

			score = board[x][y];
			for (auto& it : tetromino)
			{
				x += it[0];
				y += it[1];

				if (!IsWithinBounds(n, m, x, y))
				{
					score = 0;
					break;
				}

				score += board[x][y];
			}

			maxScore = max(maxScore, score);
		}
	}

	return maxScore;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int blockLimit = 7, rotationLimit = 4;
	long long maxScore = 0;

	for (int i = 0; i < blockLimit; i++)
	{
		for (int j = 0; j < rotationLimit; j++)
		{
			maxScore = max(maxScore, CalculateMaxScore(board, i, j));
		}
	}

	cout << maxScore;
	
	return 0;
}