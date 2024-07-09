#include <vector>
#include <queue>
#include <utility>
#include <cfloat>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            if (prob < dist[node]) {
                continue;
            }
            for (const auto& [next_node, weight] : adj[node]) {
                double new_prob = prob * weight;
                if (new_prob > dist[next_node]) {
                    dist[next_node] = new_prob;
                    pq.push({new_prob, next_node});
                }
            }
        }

        return dist[end_node];
    }
};
