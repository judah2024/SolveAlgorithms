#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string l;
    for (int i = 1; i < food.size(); i++)
    {
        string s(food[i] / 2, i + '0');
        l += s;
    }
    string r = l;
    reverse(r.begin(), r.end());
    return l + '0' + r;
}