#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> counts(201, 0);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            counts[numbers[i] + numbers[j]]++;
    
    vector<int> answer;
    answer.reserve(201);
    for (int i = 0; i < counts.size(); i++)
        if (counts[i])
            answer.push_back(i);
    return answer;
}