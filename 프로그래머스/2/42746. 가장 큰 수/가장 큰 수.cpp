#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<int> countSet(1001, 0);
    for (auto& n : numbers)
    {
        countSet[n]++;
    }

    if (countSet[0] == numbers.size())
        return "0";

    vector<string> nDict(1001);
    for (int i = 0; i <= 1000; i++)
    {
        nDict[i] = to_string(i);
    }
    sort(nDict.begin(), nDict.end(), [](const string& lhs, const string& rhs) -> bool
        {
            string a = lhs + rhs;
            string b = rhs + lhs;

            return a >= b;
        }
    );

    string answer = "";
    for (auto& it : nDict)
    {
        int i = stoi(it);
        while (countSet[i]--)
        {
            answer += it;
        }
    }

    return answer;
}