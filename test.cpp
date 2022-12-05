#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> vectGraph;
    int vertexPosition = 0;
    int numberOfRow = 1;

    for (int x = 0; x < 3; x++)
    {
        if (vertexPosition == 0)
        {
            vector<int> one(1, 0);
            vectGraph.push_back(one);
            vertexPosition++;
        }
        else
        {   
            //cout<<"gaph size"<<vectGraph.size();
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
    }
    for (int i = 0; i < vectGraph.size(); i++)
    {
        for (int j = 0; j < vectGraph[i].size(); j++)
        {
            cout << vectGraph[i][j] << " ";
        }
        cout << endl;
    }
}