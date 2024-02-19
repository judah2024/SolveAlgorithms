#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int start = section[0];
    for (int i = 0; i < section.size(); i++)
    {
        while(i != section.size())
        {
            if (section[i] - start + 1 > m)
            {
                start = section[i];
                i--;
                break;
            }
            i++;
        }
        
        answer++;
    }
    return answer;
}