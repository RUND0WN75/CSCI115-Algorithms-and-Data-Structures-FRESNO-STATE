// Lab 12 - Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>
#define max INT_MAX
using namespace std;

void print(vector<int> dist) {
    cout << "Vertex " << " Distance from source vertex\n";
    for (int i = 0; i < dist.size(); i++) cout << setw(10) << left << i << " " << dist.at(i) << endl;
}

int minDist(vector<int> dist, vector<bool> tracking_list) {
    int min = max; 
    int min_index = 0;
    for (int i = 0; i < dist.size(); i++) {
        if (tracking_list.at(i) == false and dist.at(i) < min) {
            min = dist.at(i);
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(vector<vector<int>> graph, int source) {
    vector<int> dist_list;
    vector<bool> tracking_list;
    for (int i = 0; i < graph.size(); i++) {
        dist_list.push_back(graph[source][i]);
        tracking_list.push_back(false);
    }

    dist_list.at(source) = 0;
    tracking_list.at(source) = true;
    for (int i = 0; i < graph.size(); i++) {
        int u = minDist(dist_list, tracking_list);
        tracking_list.at(u) = true;
        for (int j = 0; j < graph.size(); j++) {
            if (!tracking_list.at(j) 
                and graph[u][j] < max 
                and dist_list.at(u) < max 
                and dist_list.at(u) + graph[u][j] < dist_list.at(j)) dist_list.at(j) = dist_list.at(u) + graph[u][j];
        }
    }

    print(dist_list);
}

int main() {
    vector<vector<int>> G;
    vector<int> a{ 0,3,max,1,max };
    vector<int> b{ 3,0,6,max,7 };
    vector<int> c{ max,6,0,2,max };
    vector<int> d{ 1,max,2,0,max };
    vector<int> e{ max,7,max,max,0 };

    G.push_back(a);
    G.push_back(b);
    G.push_back(c);
    G.push_back(d);
    G.push_back(e);

    dijkstra(G, 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu