class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        
        vector<pair<int, pair<int, int>>> events;
        
        for (auto &b : buildings) {
            events.push_back({b[0], {b[2], b[1]}});
            events.push_back({b[1], {0, 0}});
        }
        
        sort(events.begin(), events.end());
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, INT_MAX});
        
        int prevHeight = 0;
        
        for (int i = 0; i < events.size();) {
            int x = events[i].first;
            
            while (i < events.size() && events[i].first == x) {
                int height = events[i].second.first;
                int right = events[i].second.second;
                
                if (height > 0)
                    pq.push({height, right});
                
                i++;
            }
            
            while (!pq.empty() && pq.top().second <= x)
                pq.pop();
            
            int currHeight = pq.top().first;
            
            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }
        
        return ans;
    }
};