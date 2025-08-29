#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjacencyList[105];
int distanceArray[105];

void dijkstra(int sourceNode)
{
    queue<pair<int, int>> pairQueue;
    pairQueue.push({sourceNode, 0});
    distanceArray[sourceNode] = 0;

    while (!pairQueue.empty())
    {
        pair<int, int> parentPair = pairQueue.front();
        pairQueue.pop();

        int parentNode = parentPair.first;
        int distanceOfParent = parentPair.second;

        for (auto childPair : adjacencyList[parentNode])
        {
            int childNode = childPair.first;
            int distanceOfChild = childPair.second;

            if (distanceOfChild + distanceOfParent < distanceArray[childNode])
            {
                distanceArray[childNode] = distanceOfChild + distanceOfParent;
                pairQueue.push({childNode, distanceArray[childNode]});
            }
        }
    }
}

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;

    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstNode, secondNode, weight;
        cin >> firstNode >> secondNode >> weight;

        adjacencyList[firstNode].push_back({secondNode, weight});
        adjacencyList[secondNode].push_back({firstNode, weight});
    }

    // memset(distanceArray, INT_MAX, sizeof(distanceArray));
    for (int i = 0; i < numberOfNode; i++)
    {
        distanceArray[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < numberOfNode; i++)
    {
        cout << i << " -> " << distanceArray[i] << endl;
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