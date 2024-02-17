#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (auto& c : s)
        if (isalpha(c))
            c += (c % 32 + n > 26) ? n - 26 : n;
    return s;
}