#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




vector<vector<int> > dijkstra(vector<vector<int> > matrix)
{
     vector<vector<int> > aList(matrix.size());

     for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
               if(matrix[i][j] == 1){
                    aList[i].push_back(j);
               }
          }
     }
     return aList;
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
     vector<vector<int> > alist = dijkstra(matrix);

     cout<<"\nAdjacency list: "<<endl;
     for(int i=0;i<alist.size();i++){
          cout<<i;
          for(int j=0;j<alist[i].size();j++){
               if(j==alist[i].size() - 1){
                    cout<<"->"<<alist[i][j]<<endl;
                    break;
               }else cout<<"->"<<alist[i][j];
          }
     }
     return 0;

}
