#include <string>
#include <vector>

using namespace std;

int GCD (int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> solution(int a, int b) {
    int gcd = GCD(a, b); 
    return {gcd, a / gcd * b};
}