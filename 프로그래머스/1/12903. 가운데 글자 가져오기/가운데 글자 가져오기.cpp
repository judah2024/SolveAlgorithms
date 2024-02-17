#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.size();
    return n % 2 ? s.substr(n / 2, 1) : s.substr(n / 2 - 1, 2);
}