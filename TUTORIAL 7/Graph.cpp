#include <iostream>
#include <climits>
using namespace std;

struct NodeConnection {
    int targetNode;
    int edgeWeight;
    NodeConnection* link;

    NodeConnection(int t, int w) {
        targetNode = t;
        edgeWeight = w;
        link = NULL;
    }
};

class MyGraph {
private:
    int totalNodes;
    NodeConnection** adjList;

public:
    MyGraph(int nodes) {
        totalNodes = nodes;
        adjList = new NodeConnection*[totalNodes];
        for (int i = 0; i < totalNodes; i++) {
            adjList[i] = NULL;
        }
    }

    void connectNodes(int start, int end, int cost) {
        NodeConnection* firstWay = new NodeConnection(end, cost);
        firstWay->link = adjList[start];
        adjList[start] = firstWay;

        NodeConnection* secondWay = new NodeConnection(start, cost);
        secondWay->link = adjList[end];
        adjList[end] = secondWay;
    }

    int findClosestNode(int* distances, bool* checked) {
        int smallest = INT_MAX;
        int indexFound = -1;

        for (int i = 0; i < totalNodes; i++) {
            if (!checked[i] && distances[i] <= smallest) {
                smallest = distances[i];
                indexFound = i;
            }
        }
        return indexFound;
    }

    int* runDijkstra(int startNode) {
        int* distances = new int[totalNodes];
        bool* checked = new bool[totalNodes];

        for (int i = 0; i < totalNodes; i++) {
            distances[i] = INT_MAX;
            checked[i] = false;
        }

        distances[startNode] = 0;

        for (int i = 0; i < totalNodes - 1; i++) {
            int current = findClosestNode(distances, checked);
            checked[current] = true;

            NodeConnection* walker = adjList[current];
            while (walker != NULL) {
                int neighbor = walker->targetNode;
                int weight = walker->edgeWeight;

                if (!checked[neighbor] && distances[current] != INT_MAX && distances[current] + weight < distances[neighbor]) {
                    distances[neighbor] = distances[current] + weight;
                }
                walker = walker->link;
            }
        }

        return distances;
    }

    ~MyGraph() {
        for (int i = 0; i < totalNodes; i++) {
            NodeConnection* walker = adjList[i];
            while (walker != NULL) {
                NodeConnection* old = walker;
                walker = walker->link;
                delete old;
            }
        }
        delete[] adjList;
    }
};

int main() {
    MyGraph net(5);
    net.connectNodes(0, 1, 4);
    net.connectNodes(0, 2, 8);
    net.connectNodes(1, 4, 6);
    net.connectNodes(1, 2, 3);
    net.connectNodes(2, 3, 2);
    net.connectNodes(3, 4, 10);

    int* finalDistances = net.runDijkstra(0);

    cout << "Path costs: ";
    for (int i = 0; i < 5; i++) {
        cout << finalDistances[i] << " ";
    }
    cout << endl;

    delete[] finalDistances;
    return 0;
}