#include <iostream>
#include <string>

using namespace std;

using PII = pair<int, int>;

bool hasBoom(const string& str, const string& boom)
{
    int idx = str.size() - boom.size();
    for (int j = 0; j < boom.size(); j++)
    {
        if (str[idx + j] != boom[j])
            return false;
    }
    return true;
}

string ExplodeString(string& orgin, const string& boom)
{
    string str;
    str.reserve(orgin.size());

    for (int i = 0; i < orgin.size(); i++)
    {
        str += orgin[i];
        if (str.back() == boom.back())
            if (str.size() >= boom.size())
                if (hasBoom(str, boom))
                    str.resize(str.size() - boom.size());
    }

    return str;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string orgin, compare;
    cin >> orgin >> compare;

    string result = ExplodeString(orgin, compare);
    cout << (result.size() == 0 ? "FRULA" : result);

    return 0;
}