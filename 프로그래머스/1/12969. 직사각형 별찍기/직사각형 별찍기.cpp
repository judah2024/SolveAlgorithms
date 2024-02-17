#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    string s(a, '*');
    for (int i = 0; i < b; i++)
    {
        cout << s << endl;
    }
    
    return 0;
}