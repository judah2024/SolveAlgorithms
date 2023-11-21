#include <vector>

using namespace std;

vector<int> CalculateEventResult(const vector<vector<int>>& users, const vector<int>& emoticons,
    vector<int>& discounts)
{
    vector<int> result = { 0, 0 };

    for (auto& user : users)
    {
        int totalPrice = 0;
        for (int i = 0; i < discounts.size(); i++)
        {
            int& rate = discounts[i];
            if (user[0] <= rate)
            {
                totalPrice += emoticons[i] * (100 - rate) / 100;
            }
        }

        if (totalPrice >= user[1])
        {
            result[0]++;
        }
        else
        {
            result[1] += totalPrice;
        }
    }

    return result;
}

vector<int> BackTracking(const vector<vector<int>>& users, const vector<int>& emoticons,
    vector<int>& discounts)
{
    int index = discounts.size();
    if (index == emoticons.size())
    {
        return CalculateEventResult(users, emoticons, discounts);
    }

    vector<int> result = { 0, 0 };
    for (auto& rate : { 40, 30, 20, 10 })
    {
        discounts.push_back(rate);
        result = max(result, BackTracking(users, emoticons, discounts));
        discounts.pop_back();
    }
    return result;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discounts;
    discounts.reserve(emoticons.size());

    return BackTracking(users, emoticons, discounts);
}