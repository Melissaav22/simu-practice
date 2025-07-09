#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &AL){
    vector<int> visited(AL.size(), -1);
    int size = AL.size();
    int groupId = 0;
    for(int i = 0; i < size ; i++){
        if(visited[i] == -1){
            queue<int> q;
            vector<int> components;
            visited[i]= 1;
            components.push_back(i);
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int neighbor: AL[node]){
                   if(visited[neighbor]== -1){
                       visited[neighbor] = 1;
                       components.push_back(neighbor);
                       q.push(neighbor);} } }
            groupId ++;
            cout << "group"<< groupId << " \n " ;
            for(int node : components){
                cout<< node << "\n";
                } } }}

int main() {
    
    int nNodes;
    cout << "number of nodes \n";
    cin >> nNodes;
        cout << "Enter edges \n";
        vector<vector<int>> AL(nNodes, vector<int>());
        int a, b;
        cin >> a >> b;
        while(a != -1 && b != -1){
            AL[a].push_back(b);
            cin >> a >> b; }
            bfs(AL);
    return 0;
}