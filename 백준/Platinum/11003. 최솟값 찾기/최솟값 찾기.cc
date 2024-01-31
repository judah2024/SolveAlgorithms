#include <iostream>
#include <deque>

using namespace std;

void PrintLocalMinimums(const int n, const int l)
{
	deque<pair<int, int>> deq;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		// 수열의 임의의 두 값 A_i, A_j (j - i < n) 사이의 값이 두 경계값보다 크다면 극소값이 될수 없다.
		// ex) L = 2, A = [1 4 2 3] 의 경우		: D_1 ~ D_2 = 1, D_3 ~ = 2로 4는 최솟값이 될수 없다.
		// 따라서, 새 값보다 큰 값들은 덱에서 제거하면
		// 덱의 front는 구간 내 최솟값이 되고, 다음 값들은 구간별 최솟값 후보들이 오름차순으로 유지되게 된다.
		while (!deq.empty())
		{
			if (deq.back().second < v) break;
			
			deq.pop_back();
		}

		// A[i]가 deq의 최댓값이므로 뒤에 넣어준다.
		deq.push_back({ i, v });

		// 구간 밖의 값들을 제거해준다.
		while (deq.front().first <= i - l)
		{
			deq.pop_front();
		}

		cout << deq.front().second << " ";
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n, l;
	cin >> n >> l;

	PrintLocalMinimums(n, l);

	return 0;
}