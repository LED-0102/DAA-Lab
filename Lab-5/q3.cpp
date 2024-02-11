#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canDivideIntoCliquesUtil(vector<vector<int>>& graph, vector<int>& colors, int vertex, int color) {
    colors[vertex] = color;

    // Assign opposite color to neighbors
    int oppositeColor = (color == 1) ? 2 : 1;
    for (int neighbor : graph[vertex]) {
        if (colors[neighbor] == 0) {
            if (!canDivideIntoCliquesUtil(graph, colors, neighbor, oppositeColor))
                return false;
        } else if (colors[neighbor] == color) {
            // Conflict: Vertex and its neighbor have the same color
            return false;
        }
    }

    return true;
}

bool canDivideIntoCliques(vector<vector<int>>& graph, int numVertices) {
    vector<int> colors(numVertices + 1, 0); // 0 indicates uncolored, 1 and 2 represent different colors

    // Start with the first vertex and color it with color 1
    if (!canDivideIntoCliquesUtil(graph, colors, 1, 1))
        return false;

    // Color remaining uncolored vertices
    for (int i = 1; i <= numVertices; ++i) {
        if (colors[i] == 0) {
            if (!canDivideIntoCliquesUtil(graph, colors, i, 1))
                return false;
        }
    }

    return true;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<int>> graph(numVertices + 1);

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    if (canDivideIntoCliques(graph, numVertices))
        cout << "The graph can be divided into two cliques." << endl;
    else
        cout << "The graph cannot be divided into two cliques." << endl;

    return 0;
}
