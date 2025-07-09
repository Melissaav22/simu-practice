// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &AL, int start){
    vector<int> layers(AL.size(), -1);
    queue<int> q;
    
    layers[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
           cout << "Visiting node " << node << " (layer: " << layers[node] << ")\n";
        for(int neighbor: AL[node]){
            if(layers[neighbor] == -1){
                layers[neighbor] = layers[node] +1;
                q.push(neighbor);
                 cout << "  Discovered node " << neighbor << " from node " << node << " (distance: " << layers[neighbor] << ")\n";
            }
        }
    }
   return layers; 
}


int main() {
    int nNodes;
    // Write C++ code here
    cout << "Ingrese el numero de nodos \n" ;
    cin >> nNodes;
    
    vector<vector<int>> AL(nNodes, vector<int>());
    int a, b;
    cout << "Ingrese arista a b \n" ;
    cin >> a >> b;
    
    while(a != -1 && b!= -1){
        AL[a].push_back(b);
        cout << "Ingrese arista a b \n" ;
        cin >> a >> b;
    }
    
    int start;
     cout << "Ingrese el nodo de inicio \n" ;
     cin >> start;
     
     
     vector<int> layers = bfs(AL, start);
     for(int i = 0; i< nNodes ; i++){
         cout << i << "->" << layers[i] << "\n";
     }
     
    
    

    return 0;
}