#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while (n)
    {
        answer = answer * 3 + n % 3;
        n /= 3;
    }
    
    return answer;
}