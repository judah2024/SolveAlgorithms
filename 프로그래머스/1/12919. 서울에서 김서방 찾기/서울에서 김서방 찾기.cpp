#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string s1 = "김서방은 ";
    string s2 = "에 있다";
    
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            return s1 + to_string(i) + s2;
        }
    }
    
    return string();
}