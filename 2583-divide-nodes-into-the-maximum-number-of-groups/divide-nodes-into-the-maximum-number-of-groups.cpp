#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    bool isBipartite(int src, vector<vector<int>>& graph, vector<int>& component) {
        queue<int> q;
        q.push(src);
        component.push_back(src);
        vector<int> color(graph.size(), -1);
        color[src] = 0; 
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto &neighbor : graph[node]) {
                if (color[neighbor] == -1) { 
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                    component.push_back(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Not bipartite
                }
            }
        }
        return true;
    }

    int bfsMaxLevel(int src, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(src);
        vector<int> vis(graph.size(), 0);
        vis[src] = 1;
        int level = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front();
                q.pop();
                for (auto &neighbor : graph[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
            level++;
        }
        return level;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> visited(n, 0);
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                if (!isBipartite(i, graph, component)) {
                    return -1; // Not bipartite, return immediately
                }

                int maxLevel = 0;
                for (int node : component) {
                    maxLevel = max(maxLevel, bfsMaxLevel(node, graph));
                }
                result += maxLevel;
                
                for (int node : component) {
                    visited[node] = 1;
                }
            }
        }
        return result;
    }
};
