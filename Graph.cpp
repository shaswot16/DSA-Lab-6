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
        vectGraph.push_back(vector<int>(1, 0));
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

    FromVertex = returnVertex(fromVertex);
    ToVertex = returnVertex(toVertex);
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

void Graph::removeEdge(char character)
{
    vertex *Vertex;
    Vertex = returnVertex(character);

    int rowToDelete = Vertex->index;
    if (vectGraph.size() > rowToDelete)
    {
        vectGraph.erase(vectGraph.begin() + rowToDelete);
    }
    unsigned columnToDelete = Vertex->index;

    for (unsigned i = 0; i < vectGraph.size(); ++i)
    {
        if (vectGraph[i].size() > columnToDelete)
        {
            vectGraph[i].erase(vectGraph[i].begin() + columnToDelete);
        }
    }
    numberOfRow--;
    vertexPosition--;
    for (int i = 0; i < graph.size(); i++)
    {
        if(graph[i]->index>rowToDelete){
            graph[i]->index--;
        }
       
    }

};

int Graph::outDegree(char character)
{
    vertex *Vertex;
    int count = 0;
    Vertex = returnVertex(character);
    for (int j = 0; j < vectGraph[Vertex->index].size(); j++)
    {
        if (vectGraph[Vertex->index][j] == 1)
        {
            count++;
        }
    }
    return count;
};
int Graph::inDegree(char character)
{
    vertex *Vertex;
    Vertex = returnVertex(character);
    int count = 0;
    for (int j = 0; j < vectGraph[Vertex->index].size(); j++)
    {
        if (vectGraph[j][Vertex->index] == 1)
        {
            count++;
        }
    }
    return count;
};

void Graph::numOfEdges(char vertex)
{
    cout << "Number of Edges of " << vertex << " is " << (inDegree(vertex) + outDegree(vertex)) << endl;
}

vertex *Graph ::returnVertex(char character)
{
    vertex *ToVertex;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i]->Character == character)
        {
            ToVertex = graph[i];
            return ToVertex;
        }
    }
    return nullptr;
}