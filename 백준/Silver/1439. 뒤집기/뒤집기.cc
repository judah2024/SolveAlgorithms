#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> bitArray(2, 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1]) continue;

        bitArray[s[i] - '0']++;
    }

    cout << min(bitArray[0], bitArray[1]);

    return 0;
}