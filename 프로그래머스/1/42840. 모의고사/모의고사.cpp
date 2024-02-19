#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> papers = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    
    vector<int> correctCnt(3, 0);
    for (int i = 0; i < answers.size(); i++)
        for (int j = 0; j < 3; j++)
            if (papers[j][i % papers[j].size()] == answers[i])
                correctCnt[j]++;
    
    int maxValue = 0;
    for (auto& cnt : correctCnt)
    {
        maxValue = max(maxValue, cnt);
    }
    
    vector<int> luckyguys;
    for (int i = 0; i < 3; i++)
    {
        if (correctCnt[i] == maxValue)
        {
            luckyguys.push_back(i + 1);
        }
    }
    
    return luckyguys;
}