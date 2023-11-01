#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        swap(a, b);
        b += a;
    }

    cout << a;
    return 0;
}