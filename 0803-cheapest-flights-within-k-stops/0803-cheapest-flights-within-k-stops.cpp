#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto& it : flights) {
            adj[it[0]].emplace_back(it[1], it[2]);
        }

        // Min-heap to store (stops, node, cost)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [stops, node, cost] = pq.top();
            pq.pop();

           
            if (stops > k) continue;

            for (auto& [nextNode, price] : adj[node]) {
                int newCost = cost + price;

                if (newCost < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = newCost;
                    pq.push({stops + 1, nextNode, newCost});
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            ans = min(ans, dist[dst][i]);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
