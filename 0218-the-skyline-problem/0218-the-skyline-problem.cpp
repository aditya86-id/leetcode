#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 1. Create sweep-line events: {x, -height, right}
        vector<vector<int>> events;
        events.reserve(buildings.size() * 2);
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2], b[1]}); // Start
            events.push_back({b[1], 0, b[1]});     // End
        }
        
        // 2. Sort: x ascending, then height ascending
        // Negative heights ensure taller starts process before shorter ones/ends
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        // 3. Max-heap: {height, right_boundary}
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, INT_MAX); // Ground sentinel (height 0, never expires)
        
        vector<vector<int>> result;
        int prev_max_h = 0;
        
        // 4. Sweep
        for (const auto& e : events) {
            int x = e[0], h = e[1], r = e[2];
            
            if (h < 0) {
                // Building starts
                pq.emplace(-h, r);
            } else {
                // Building ends: lazily remove expired buildings
                // CRITICAL FIX: pq.size() > 1 ensures ground sentinel stays alive
                while (pq.size() > 1 && pq.top().second <= x) {
                    pq.pop();
                }
            }
            
            int curr_max_h = pq.top().first;
            if (curr_max_h != prev_max_h) {
                result.push_back({x, curr_max_h});
                prev_max_h = curr_max_h;
            }
        }
        
        return result;
    }
};