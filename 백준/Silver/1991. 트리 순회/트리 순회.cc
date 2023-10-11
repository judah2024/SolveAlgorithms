#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void PrintTree(unordered_map<char, vector<char>>& bTree, char node, const int mode)
{
    if (node == '.')
    {
        return;
    }

    if (bTree[node].size() < 2)
    {
        return;
    }

    if (mode == 0)
        cout << node;
    PrintTree(bTree, bTree[node][0], mode);
    if (mode == 1)
        cout << node;
    PrintTree(bTree, bTree[node][1], mode);
    if (mode == 2)
        cout << node;
}

int main()
{
    unordered_map<char, vector<char>> bTree;
    bTree['.'];
    
    int n;
    cin >> n;

    char a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        bTree[a].reserve(2);

        bTree[a].push_back(b);
        bTree[a].push_back(c);
    }

    for (int i = 0; i < 3; i++)
    {
        PrintTree(bTree, 'A', i);
        cout << "\n";
    }

    return 0;
}
