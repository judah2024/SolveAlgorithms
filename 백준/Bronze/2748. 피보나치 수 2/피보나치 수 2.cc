#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    long long a = 0, b = 1;

    for (int i = 1; i <= n; i++)
    {
        swap(a, b);
        b += a;
    }

    cout << a;
    return 0;
}