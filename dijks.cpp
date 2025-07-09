// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <climits>


using namespace std;

void Dijkstra(int start, vector<vector<pair<int,int>>> &AL){
    vector<int> dist(AL.size(), INT_MAX);
    vector<int> visited(AL.size(), -1);
     dist[start] = 0;
    int cont_explored = 0;
    while(cont_explored != AL.size()){
         int min_index = -1;
         int min_dist = INT_MAX;
         for(int i = 0; i < AL.size(); i++){
             if(visited[i] == -1 && dist[i] != INT_MAX && dist[i]< min_dist){
                 min_index= i;
                 min_dist = dist[i]; }}
         if (min_index == -1) {
            break; 
             }

         for(pair<int, int> neighbor: AL[min_index]){
             int myOption = dist[min_index] + neighbor.second;
             if(myOption < dist[neighbor.first]){
                 dist[neighbor.first] = myOption;}}
         visited[min_index] = 1;
         cont_explored++;}
         for(int dist: dist){
             if(dist == INT_MAX){
                 cout<< "unreachable \n"; 
             }else{
             cout<< dist << "\n" ; }}}
int main() {
    int nNodes;
    int a, b, w;
    int start;
    cout<< "Ingrese el numero de nodos \n";
    cin >> nNodes;
    vector<vector<pair<int, int>>> AL(nNodes);
    cout<< "Ingrese la arista a -> b y peso \n";
    cin >> a >> b >> w;
    while(a!= -1 && b != -1 && w != -1){
        AL[a].push_back({b, w});
        cin >> a >> b >> w;}
     cout<< "Ingrese el starting point \n";
     cin >> start;
     Dijkstra(start, AL);

    return 0;
}