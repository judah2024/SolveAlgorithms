#include <vector>
#include <iostream>
using namespace std;

vector<bool> CreateIsPrime(const int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i += 2)
    {
        for (int j = i + i; j <= n; j += i)
            isPrime[j] = false;
        i = (i == 2) ? i - 1 : i;
    }
    return isPrime;
}

int solution(vector<int> nums) {
    vector<bool> isPrime = CreateIsPrime(50000);
    const int n = nums.size();
    
    int answer = 0;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (isPrime[nums[i] + nums[j] + nums[k]])
                    answer++;

    return answer;
}