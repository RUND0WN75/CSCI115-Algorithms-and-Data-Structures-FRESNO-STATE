// Lab10 BFS-DFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    private:
        vector<bool> visited;
        vector<vector<int>> Adj;
        queue<int> Q; 
    public:
        Graph(vector<vector<int>> Adj) {
            this->Adj = Adj;
            visited = vector<bool>(Adj.size(),false);
        }

        void dfs(int n) {
            visited.at(n) = true;
            cout << n << " ";
            for (int node : this->Adj.at(n)) {
                if (!visited.at(node)) this->dfs(node);
            }
        }

        void bfs(int n) {
            visited = vector<bool>(Adj.size(), false);
            visited.at(n) = true;
            Q = queue<int> (); //Calling constructor of STL queue
            Q.push(n);
            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();
                for (int x : this->Adj.at(node)) {
                    if (!visited.at(x)) {
                        visited.at(x) = true;
                        Q.push(x);
                    }
                }
                if (!Q.empty()) cout << Q.front() << " ";
            }
        }
};

int main() {
    vector<vector<int>> Adj;

    vector<int> a{ 1,5 };
    vector<int> b{ 1,4 };
    vector<int> c{ 2,3 };
    vector<int> d{ 1,3 };
    vector<int> e{ 2,4 };
    vector<int> f{ 0,1,2,3 };

    Adj.push_back(a);
    Adj.push_back(b);
    Adj.push_back(c);
    Adj.push_back(d);
    Adj.push_back(e);
    Adj.push_back(f);

    Graph x = Graph(Adj);

    cout << "DFS: ";
    x.dfs(0);
    cout << endl;
    cout << "BFS: ";
    x.bfs(0);
    cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu