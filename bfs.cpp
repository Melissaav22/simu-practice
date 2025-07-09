// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<bool> bfs(const vector<vector<int>> &AL, int start){
    vector<bool> visited(AL.size(), false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbor: AL[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return visited;
}

int main() {
    
    int nNodes;
    cout<< "Ingrese numero de nodos " << endl; 
    cin >> nNodes;
    
    vector<vector<int>> AL(nNodes, vector<int>());
    int a, b;
    cout<< "Ingrese nodos a y b" << endl; 
    cin >> a >> b ;
    while(a != -1 && b != -1){
        AL[a].push_back(b);
        cout << "Ingresar arista (a b): ";
        cin >> a >> b;
    }
    
    int start;
    cout << "Ingrese nodo de inicio: \n";
    cin >> start;
    cout << "\n";
    vector<bool> visited = bfs(AL, start);
       cout << "Nodos con conexión al nodo de inicio:\n";
    for (int i = 0; i < nNodes; i++)
    {
        cout << i << " -> " << (visited[i] ? "true" : "false") << "\n";
    }
    return 0;
    }

  
