#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
    Graph * newGraph = new Graph(false);
    if(newGraph->isDirected()){
        cout<<"It is a dorected graph"<<endl;
    }
    else{
        cout<<"It is not a directed graph"<<endl;
    }

    newGraph->addVertex('a');
    newGraph->addVertex('b');
    newGraph->addVertex('c');
    newGraph->addVertex('d');
    newGraph->displayVertex();
    newGraph->addEdge('a','b');
    newGraph->addEdge('c','d');
    
    newGraph->displayEdge();
    
    int oDegree=newGraph->outDegree('c');
    cout<<"OutDegree of c is "<< oDegree<<endl;

    int iDegree=newGraph->inDegree('d');
    cout<<"Indegree of d is "<< iDegree<<endl;

    newGraph->numOfEdges('d');

    newGraph->removeEdge('a');
    cout<<endl;
    newGraph->displayEdge();

    newGraph->addVertex('e');
    newGraph->displayEdge();

    newGraph->addEdge('c','e');
    newGraph->addEdge('b','d');
    newGraph->addEdge('b','c');
    newGraph->addEdge('e','d');

    newGraph->displayEdge();
    newGraph->numOfEdges('c');


    

}
