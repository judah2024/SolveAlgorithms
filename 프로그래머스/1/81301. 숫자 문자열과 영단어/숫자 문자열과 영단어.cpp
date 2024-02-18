#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>

using namespace std;

int solution(string s) {
    unordered_map<string, pair<int, int>> alphaInfos = 
    {
        {"ze", {0, 3}}, {"on", {1, 2}}, {"tw", {2, 2}}, {"th", {3, 4}}, {"fo", {4, 3}},
        {"fi", {5, 3}}, {"si", {6, 2}}, {"se", {7, 4}}, {"ei", {8, 4}}, {"ni", {9, 3}}
    };
    
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            answer = answer * 10 + (s[i] - '0');
        }
        else
        {
            string numSign = s.substr(i, 2);
            const auto& alInfo = alphaInfos[numSign];
            answer = answer * 10 + alInfo.first;
            i += alInfo.second;
        }
    }
    return answer;
}