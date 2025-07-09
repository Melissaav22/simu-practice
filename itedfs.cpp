// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<bool> dfs_ite(vector<vector<int>> &AL, int start){
    vector<bool> visited(AL.size(), false);
     stack<int> next;
     next.push(start);
     while(!next.empty()){
         int u = next.top();
         next.pop();
         if(!visited[u]){
             visited[u] = true;
             cout << u << "->" ;
             int j = AL[u].size() -1;
             for(int i =j; i >= 0; i--){
                 int v= AL[u][i];
                 if(visited[v]){continue;}
                 next.push(v);} } }
         cout<< "end \n"; return visited;} 
int main() {
int nNodes;
cout<< "Ingresa el numero de nodos \n";
cin >> nNodes;
int a,b;
vector<vector<int>> AL(nNodes, vector<int>());
cout << "Ingresa la arista a -> b \n";
cin >> a >> b;
while(a != -1 && b != -1){
    AL[a].push_back(b);
    cin >> a >> b;}
int start;
cout << "Ingrese el nodo de inicio \n";
cin >> start;
vector<bool> result = dfs_ite(AL, start);

    return 0;
}