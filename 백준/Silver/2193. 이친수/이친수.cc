#include <iostream>
#include <vector>

using namespace std;

long long CountPinaryNumbers(const int n)
{
	// 최상위 2개의 비트는 10로 고정이므로 0 < n < 3 이면 계산할 필요없이 1이다.
	// 계산의 편의를 위해 n = 0 이면 count = 0 으로 정의한다.
	vector<long long> counts(n + 1, 0);
	counts[1] = counts[2] = 1;

	if (n >= 3)
	{
		// counts[i] : i번째 비트가 최상위 비트인 경우의 count
		// counts[i] = 1 + Σcounts[k] , 0 < k < i - 1
		// counts[i] - counts[i - 1] = counts[i - 2]
		// counts[i] = counts[i - 1] + counts[i - 2] , 2 < i (피보나치 수열의 수식과 동일)
		for (int i = 3; i <= n; i++)
		{
			counts[i] = counts[i - 1] + counts[i - 2];
		}
	}

	return counts[n];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n;
	cin >> n;

	cout << CountPinaryNumbers(n);

	return 0;
}