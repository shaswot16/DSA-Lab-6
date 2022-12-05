#include "Graph.h"

bool Graph::isDirected()
{
    return (directed) ? true : false;
};

void Graph::addVertex(char newVertexChar)
{
    vertex *newVertex = new vertex(newVertexChar, vertexPosition);
    graph.push_back(newVertex);

    if (vertexPosition == 0)
    {
        vectGraph.push_back(vector<int> (1, 0));
    }
    else
    {
        for (int i = 0; i < vectGraph.size(); i++)
        {
            for (int j = 0; i < numberOfRow; i++)
            {
                vectGraph[i].push_back(0);
            }
        }
        numberOfRow++;
        vectGraph.push_back(vector<int>(vectGraph.size() + 1, 0));
    }

    vertexPosition++;
};

void Graph::displayVertex()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << graph[i]->Character << "" << graph[i]->index << endl;
    }
};

void Graph::addEdge(char fromVertex, char toVertex)
{
    vertex *FromVertex;
    vertex *ToVertex;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i]->Character == fromVertex)
        {
            FromVertex = graph[i];
            break;
        }
    }
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i]->Character == toVertex)
        {
            ToVertex = graph[i];
            break;
        }
    }

    vectGraph[FromVertex->index][ToVertex->index] = 1;
};

void Graph::displayEdge()
{
    cout << "Inside edge display" << endl;

    for (int i = 0; i < vectGraph.size(); i++)
    {
        for (int j = 0; j < vectGraph[i].size(); j++)
        {
            cout << vectGraph[i][j] << " ";
        }
        cout << endl;
    }
};

// void Graph: removeEdge(){

// };

// int Graph: numEdges(){

// };

// int Graph: outdegree(){

// }

// char Graph: neighbours(){

// }
