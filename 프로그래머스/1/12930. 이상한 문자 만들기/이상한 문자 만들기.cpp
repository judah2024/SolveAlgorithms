#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int cnt = 0;
    for (auto& it : s)
    {
        if (it == ' ')
        {
            cnt = 0;
        }
        else
        {
            cnt++;
            it = (cnt & 1) ? toupper(it) : tolower(it);
        }
    }
    return s;
}