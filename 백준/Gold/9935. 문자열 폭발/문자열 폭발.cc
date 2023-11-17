#include <iostream>
#include <string>
#include <stack>

using namespace std;

using PII = pair<int, int>;

string ExplodeString(string& orgin, const string& compare)
{
    stack<PII> stk;
    int oI = 0, cI = 0, oE = 0;

    for (int i = 0; i < orgin.size(); i++, oE++)
    {
        orgin[oE] = orgin[i];

        if (orgin[oE] == compare[cI])
        {
            cI++;
        }
        else
        {
            if (cI > 0)
            {
                stk.push({ oI, oE });

                i--;
                oE--;
                oI = oE;
            }
            else
            {
                while (!stk.empty())
                {
                    stk.pop();
                }
            }
            cI = 0;
            oI++;
        }
        
        if (cI == compare.size())
        {
            oE -= cI;
            cI = 0;

            if (!stk.empty())
            {
                auto prev = stk.top(); stk.pop();
                oI = prev.first;
                cI = prev.second - oI;
            }
        }
    }

    for (int i = oE; i < orgin.size(); i++)
    {
        orgin[i] = ' ';
    }

    string newStr;
    newStr.reserve(orgin.size());
    for (auto& it : orgin)
    {
        if (it != ' ')
        {
            newStr += it;
        }
    }
    
    return newStr;
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