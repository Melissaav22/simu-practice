// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &AL, int start, vector<bool> &visited, stack<int> &topo ){
    visited[start] = true;
    for(int neighbor: AL[start]){
        if(!visited[neighbor]){
            dfs(AL, neighbor, visited, topo);
            
        }
        
    }topo.push(start);}


void topo_sort(vector<vector<int>> &AL){ vector<bool> visited(AL.size(), false);
stack<int> topo;
    for(int i = 0; i < AL.size(); i++){
        if(!visited[i]){
            dfs(AL, i, visited, topo);
        }
    }
   while(!topo.empty()){
       cout<< topo.top() << "\n";
       topo.pop();}
    cout<< "end \n"; }
    
int main() {
    int nNodes;
    int a,b;
    cin >> nNodes;
       vector<vector<int>> AL(nNodes, vector<int>());
    cout<< "Ingrese sus aristas";
    cin >> a >>b ;
    while(a!= -1 && b!= -1){
        AL[a].push_back(b);
        cin >> a >> b;
    }
    topo_sort(AL);
    return 0;
}