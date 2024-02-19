#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isBabble(string& babble)
{
    unordered_set<string> babbles= { "aya", "ye", "woo", "ma" };
    string prevSub;
    for (int i = 0; i < babble.size(); i++)
    {
        string sub2 = babble.substr(i, 2);
        string sub3 = babble.substr(i, 3);
            
        if (babbles.count(sub2)) 
        {
            i += 1;
            sub3 = sub2;
        }
        else if (babbles.count(sub3)) 
        {
            i += 2;
        }
        else 
        {
            return false;
        }
        
        if (prevSub == sub3) return false;
        prevSub = sub3;
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (auto& babble : babbling)
    {
        if (isBabble(babble)) answer++;
    }
    return answer;
}