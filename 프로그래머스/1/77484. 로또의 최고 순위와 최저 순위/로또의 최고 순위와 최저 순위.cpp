#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    const vector<int> rank = { 6, 6, 5, 4, 3, 2, 1 };
    
    vector<int> numCounts(46, 0);
    for (const auto& num : lottos)
        numCounts[num]++;
    
    int cnt = 0;
    for (const auto& num : win_nums)
        if (numCounts[num]) cnt++;
    
    return {rank[cnt + numCounts[0]], rank[cnt]};
}