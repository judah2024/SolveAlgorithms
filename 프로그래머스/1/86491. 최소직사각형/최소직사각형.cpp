#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    for (auto& card : sizes)
    {
        if (card[0] < card[1]) swap(card[0], card[1]);
        x = max(x, card[0]);
        y = max(y, card[1]);
    }
    
    return x * y;
}