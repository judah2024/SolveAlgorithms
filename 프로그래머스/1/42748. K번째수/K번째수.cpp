#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    answer.reserve(commands.size());
    for (const auto& com : commands)
    {
        vector<int> counts(101, 0);
        for (int i = com[0] - 1; i < com[1]; i++)
        {
            counts[array[i]]++;
        }
        
        int findIdx = com[2];
        for (int i = 1; i < counts.size(); i++)
        {
            findIdx -= counts[i];
            if (findIdx <= 0)
            {
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}