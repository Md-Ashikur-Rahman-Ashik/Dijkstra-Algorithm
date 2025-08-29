#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;
    vector<pair<int, int>> adjacencyList[numberOfNode];

    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstNode, secondNode, weight;
        cin >> firstNode >> secondNode >> weight;

        adjacencyList[firstNode].push_back({secondNode, weight});
        adjacencyList[secondNode].push_back({firstNode, weight});
    }

    for (int i = 0; i < numberOfNode; i++)
    {
        cout << i << " -> ";
        for (auto childPair : adjacencyList[i])
        {
            cout << childPair.first << " " << childPair.second << ", ";
        }

        cout << endl;
    }

    return 0;
}

// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5