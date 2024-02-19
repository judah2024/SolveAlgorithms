#include <string>
#include <vector>

using namespace std;

int CalculateDividors(int n)
{
    int ret = 1;
    for (int i = 2; i <= n; i += 2)
    {
        int cnt = 1;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
        ret *= cnt;
        i == 2 ? i-- : i;
    }
    return ret;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++)
    {
        int knPower = CalculateDividors(i);
        answer += (knPower > limit) ? power : knPower;
    }
    return answer;
}