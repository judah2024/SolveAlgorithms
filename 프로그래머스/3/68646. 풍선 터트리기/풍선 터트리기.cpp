#include <string>
#include <vector>
#include <stack>

using namespace std;

bool IsHill(const int prev, const int curr, const int next)
{
    return prev < curr && next < curr;
}

int solution(vector<int> a)
{
    stack<int> stk;
    stk.push(a[0]);
    
    for (int i = 1; i < a.size() - 1; i++)
    {
        int curr = a[i];
        int prev = stk.top();
        int next = a[i + 1];
        
        if (IsHill(prev, curr, next))
        {
            while (stk.size() > 1)
            {
                curr = prev; stk.pop();
                prev = stk.top();

                if (!IsHill(prev, curr, next))
                {
                    stk.push(curr);
                    break;
                }

            }
        }
        else
        {
            stk.push(a[i]);
        }
    }

    stk.push(a.back());

    return stk.size();
}