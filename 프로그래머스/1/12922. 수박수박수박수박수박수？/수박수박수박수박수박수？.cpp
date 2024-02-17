#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    const string watermelon = "수박";
    string answer;
    while(n > 0)
    {
        n -= 2;
        answer += "수";
        if (n > -1)
        {
            answer += "박";
        }
    }
    
    return answer;
}