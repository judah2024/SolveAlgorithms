#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    int answer = 0;
    for (int i = m - 1; i < score.size(); i+= m)
        answer += (score[i] * m);
    return answer;
}