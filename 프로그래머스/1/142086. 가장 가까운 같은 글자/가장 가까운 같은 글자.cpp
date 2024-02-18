#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> offsets(26, -1);
    vector<int> answer(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        answer[i] = (offsets[idx] == -1) ? offsets[idx] : i - offsets[idx];
        offsets[idx] = i;
    }
    return answer;
}