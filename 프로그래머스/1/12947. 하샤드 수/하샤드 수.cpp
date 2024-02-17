#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int digitSum = 0;
    for (int n = x; n > 0; n /= 10)
    {
        digitSum += (n % 10);
    }
    return (x % digitSum) ? false : true;
}