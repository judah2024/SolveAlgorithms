#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer(score.size());
    priority_queue<int, vector<int>, greater<int>> priorQue;
    for (int i = 0; i < score.size(); i++)
    {
        priorQue.push(score[i]);
        if (priorQue.size() > k) priorQue.pop();
        answer[i] = priorQue.top();
    }
    return answer;
}