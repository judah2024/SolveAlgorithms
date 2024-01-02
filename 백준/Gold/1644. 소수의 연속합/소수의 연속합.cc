#include <iostream>
#include <vector>

using namespace std;

vector<int> CreatePrimes(const int n)
{
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= n; i += 2)
	{
		if (!isPrime[i]) continue;
		
		for (int j = i + i; j <= n; j += i)
			isPrime[j] = false;
		
		i == 2 ? i-- : i;
	}

	vector<int> primes;
	for (int i = 2; i <= n; i += 2)
	{
		if (isPrime[i]) primes.push_back(i);
		i == 2 ? i-- : i;
	}

	return primes;
}

int CountSumCase(const int n, const vector<int>& primes)
{
	int i = 0, j = 0, t = primes.size();
	int subSum = 0, ret = 0;

	while (true)
	{
		if (subSum == n) ret++;
		if (j == t) break;
		if (subSum <= n) subSum += primes[j++];
		while (subSum > n) subSum -= primes[i++];
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> primes = CreatePrimes(n);
	cout << CountSumCase(n, primes);

	return 0;
}