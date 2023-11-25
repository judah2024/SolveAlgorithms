#include <string>
#include <vector>
#include <stack>

using namespace std;
int solution(vector<int> a) {
    int answer = a.size();
    stack<int> stack;
    for(int comp : a){
        while(!stack.empty() && comp < stack.top()){
            stack.pop();
            if(!stack.empty())
                answer--;
        }
        stack.push(comp);
    }
    return answer;
}
