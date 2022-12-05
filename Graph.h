#include <vector>
#include <iostream>
using namespace std;

#ifndef GRAPH
#define GRAPH

class vertex
{

public:
    char Character;
    int index;
    vertex(char c, int i)
    {
        Character = c;
        index = i;
    }
    vertex() = default;
};

class Graph
{

private:
    int vertexPosition = 0;
    bool directed;
    vertex *head;

public:
    int numberOfRow = 1;
    vertex v;
    vector<vector<int>> vectGraph;
    Graph(bool directed)
    {
        this->directed = directed;
    }
    vector<vertex *> graph;
    bool isDirected();
    void addVertex(char newVertex);
    void addEdge(char fromVertex, char toVertex);
    void removeEdge(char vertex);
    void numOfEdges(char vertex);
    int outDegree(char vertex);
    int inDegree(char vertex);
    char neighbours();
    void displayVertex();
    void displayEdge();
    vertex* returnVertex(char vertex);//Returns the pointer to the vertex after giving the character/name of vertex

};

#endif