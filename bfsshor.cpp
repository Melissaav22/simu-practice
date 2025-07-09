// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &AL, int start){
    vector<int> parent(AL.size(), -1);
    
    queue<int> q;
    parent[start] = start;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbor: AL[node]){
            if(parent[neighbor] == -1){
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    return parent;
}

int main() {
    int nNodes;
    cout << "Ingrese el numero de nodos \n";
    cin >> nNodes;
    cout << "\n";
    
    vector<vector<int>> AL(nNodes, vector<int>());
    int a, b;
    int start, end;
    cout << "Write the nodes you have like a b";
    cin >> a >> b;
    while (a != -1 && b != -1){
       AL[a].push_back(b);
       cin >> a >> b;
       
    }
    cout << "Write starting node \n";
    cin >> start;
    cout << "Write the finish node \n";
    cin >> end;
    

    vector<int> parents = bfs(AL, start);
    cout << "Ruta más corta del inicio al fin:\n";

    
    if(parents[end] == -1){
        cout << "there is not a possible path \n";
    } else{
        stack<int> path;
        while(end != start){
        path.push(end);
        end = parents[end];
        }
        
        cout << start;
        while(!path.empty()){
            cout << " -> " << path.top();
            path.pop();
        }
         cout << "\n";
        
        
    }

    return 0;
}