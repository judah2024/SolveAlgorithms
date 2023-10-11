#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void PreOrder(unordered_map<char, vector<char>>& bTree, char node)
{
    if (node == '.')
    {
        return;
    }

    if (bTree[node].size() < 2)
    {
        return;
    }

    cout << node;
    PreOrder(bTree, bTree[node][0]);
    PreOrder(bTree, bTree[node][1]);
}

void InOrder(unordered_map<char, vector<char>>& bTree, char node)
{
    if (node == '.')
    {
        return;
    }

    if (bTree[node].size() < 2)
    {
        return;
    }

    InOrder(bTree, bTree[node][0]);
    cout << node;
    InOrder(bTree, bTree[node][1]);
}

void PostOrder(unordered_map<char, vector<char>>& bTree, char node)
{
    if (node == '.')
    {
        return;
    }

    if (bTree[node].size() < 2)
    {
        return;
    }

    PostOrder(bTree, bTree[node][0]);
    PostOrder(bTree, bTree[node][1]);
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

    PreOrder(bTree, 'A');
    cout << "\n";
    InOrder(bTree, 'A');
    cout << "\n";
    PostOrder(bTree, 'A');
    cout << "\n";

    return 0;
}
