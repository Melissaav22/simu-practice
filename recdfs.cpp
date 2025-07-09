// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// recursive for sure

void dfs_rec(vector<vector<int>> &AL, int start, vector<bool> &visited){
    cout << "->" << start << " ";
    visited[start] = true;
    for( int neighbor: AL[start]){
        if(visited[neighbor]){
            continue;}
        dfs_rec(AL, neighbor, visited);}}
        
vector<bool> dfs(vector<vector<int>> &AL, int start){
    vector<bool> visited(AL.size(), false);
    dfs_rec(AL, start, visited);
    cout<< "end \n";
    return visited;}
    
int main() {
   int nNodes;
   cout << "Ingresa el numero de nodos \n";
   cin >> nNodes;
   
   vector<vector<int>> AL(nNodes, vector<int>());
   int a,b;
   int start;
    cout << "Ingresa las aristas a b \n";
    cin >> a >> b;
    while(a != -1 && b != -1){
       AL[a].push_back(b);
       cin >> a >> b;
    }
      cout << "Ingresa el node de inicio \n";
      cin >> start;
    vector<bool> result = dfs(AL, start); 
    
    
   

    return 0;
}