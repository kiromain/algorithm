#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int NO_PARENT = -1;

void printPath(int currentVertex, vector<int> parents)
{

    // Base case : Source node has
    // been processed
    if (currentVertex == NO_PARENT) {
        return;
    }
    printPath(parents[currentVertex], parents);
    cout << currentVertex << " ";
}

void printS(int startVertex, vector<int> distances,
                   vector<int> parents)
{
    int nVertices = distances.size();
    cout << "Vertex\t Distance\tPath";

    for (int vertexIndex = 0; vertexIndex < nVertices;
         vertexIndex++) {
        if (vertexIndex != startVertex) {
            cout << "\n" << startVertex << " -> ";
            cout << vertexIndex << " \t\t ";
            cout << distances[vertexIndex] << "\t\t";
            printPath(vertexIndex, parents);
        }
    }
}

void dijkstra(vector<vector<int> > adjMatrix,int svertex)
{
     int nVertices = adjMatrix[0].size();
     //shortesdistances
     vector<int> sds(nVertices);
     vector<bool> added(nVertices);

     for(int i=0;i<nVertices;i++){
          sds[i]=INT_MAX;
          added[i]=false;
     }

     sds[svertex] = 0;

     vector<int> parents(nVertices);

     parents[svertex] = NO_PARENT;

     for(int i=1;i<nVertices;i++){
          int nearestvertex = -1;
          int sd = INT_MAX;
          for(int j=0;j<nVertices;j++){
               if(!added[j] && sds[j] < sd){
                    nearestvertex = j;
                    sd = sds[j];
               }
          }

          added[nearestvertex] = true;

          for (int j = 0; j < nVertices;j++) {
            int edgeDistance= adjMatrix[nearestvertex][j];
            if (edgeDistance > 0 && ((sd + edgeDistance)< sds[j])) {
                parents[j] = nearestvertex;
                sds[j]= sd + edgeDistance;
            }
        }
     }
     printS(svertex,sds,parents);
}

int main()
{
     int s;

     //cout << "\nPodaj plik, z ktorego chcesz wczytac dane:\n";
     string fname;
     //cin.ignore();
     //getline(cin,fname);

     ifstream plik;
     plik.open("graph.txt");

     if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc podanego pliku.\n";
     }

     plik>>s;

     vector<vector<int> > matrix;

     int x;
     for(int i=0;i<s;i++){
          matrix.push_back(vector<int>());
          for(int j=0;j<s;j++){
               plik>>x;
               matrix[i].push_back(x);
          }
     }

     cout<<"Adjacency matrix inserted from a file: "<<endl;
     for(int i=0;i<s;i++){
          for(int j=0;j<s;j++){
               cout<<matrix[i][j]<<" ";
          }
          cout<<endl;
     }
     cout<<endl;

     int i;
     cout<<"Insert a starting vertex: "<<endl;
     cin>>i;
     dijkstra(matrix,i);

     return 0;

}
