#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    const vector<string> weekDays = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    const vector<int> monthFirsts = { -1, 4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3 };
    int day = (monthFirsts[a] + b - 1) % 7;
    return weekDays[day];
}