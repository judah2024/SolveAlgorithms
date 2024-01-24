#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int CountRotation(const int n, const int m)
{
	// 회전할 deque (한 방향 회전으로 반대 방향 카운트를 계산 할 수 있으므로 stack, queue만으로도 가능하다)
	deque<int> nDeq(n);
	for (int i = 0; i < n; i++)
		nDeq[i] = i + 1;

	// 찾아낼 수의 배열
	vector<int> nVec(m);
	for (int i = 0; i < m; i++)
		cin >> nVec[i];

	int rotCnt = 0;
	for (auto& it : nVec)
	{
		// 같은 수가 나올 때까지 한쪽방향으로 계속 회전하면서 cnt를 늘린다.
		int cnt = 0;
		while (nDeq[0] != it)
		{
			auto front = nDeq[0];
			nDeq.pop_front();
			nDeq.push_back(front);
			cnt++;
		}

		// 더 회전 횟수가 뱡향의 값을 더해준다.
		rotCnt += (cnt < nDeq.size() - cnt) ? cnt : nDeq.size() - cnt;
		// 찾은 값이 여전히 남아있으므로 제거해준다.
		// rotCnt에 값을 더하는 연산에 사라지기 전 size가 필요하므로 해당 연산 이후에 제거한다.(size값을 미리 저장하는 것도 가능)
		nDeq.pop_front();
	}
	return rotCnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	cout << CountRotation(n, m);

	return 0;
}