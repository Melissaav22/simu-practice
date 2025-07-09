// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define STOP -100
using namespace std;



void Heaped_Dijkstra(vector<vector<pair<int, int>>> &AL, int start, int e){
    vector<int> prev(AL.size(),STOP );
    vector<int> dist(AL.size(), INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
    
    dist[start] = 0;
    min_heap.push(make_pair(dist[start],start));
    while(!min_heap.empty()){
        int node = min_heap.top().second;
        int dis = min_heap.top().first;
        min_heap.pop();
        for(pair<int,int> neighbor: AL[node]){
            int myOption= neighbor.second + dis;
            if(myOption < dist[neighbor.first]){
                dist[neighbor.first] = myOption;
                prev[neighbor.first] = node;
                min_heap.push(make_pair(myOption, neighbor.first));
            }
        }
    }
    if(prev[e] == STOP){
        cout<< "Unreachable node \n";
    } else{
       stack<int> path;
       path.push(e);
        e = prev[e];
        while(e != STOP){
            path.push(e);
            e= prev[e];
        }
        while(!path.empty()){
            cout << path.top();
            path.pop();
             if(!path.empty()) cout << " -> ";
        }
    }
  
    
}

int main() {
 
    vector<vector<pair<int, int>>> AL(5); // 5 nodes: 0 to 4

    AL[0].push_back({1, 4});
    AL[0].push_back({2, 1});
    AL[2].push_back({1, 2});
    AL[2].push_back({3, 5});
    AL[1].push_back({3, 1});
    AL[3].push_back({4, 3});

    int start = 0;
    int end = 4;

    Heaped_Dijkstra(AL, start, end);

    return 0;
}

