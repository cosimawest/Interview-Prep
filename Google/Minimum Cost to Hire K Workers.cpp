class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // ugh this is really difficult for me to understand
        
        // esentially, you sort each worker by their wage:quality ratio
        // and then pick the lowest k number of them
        //
        // then you sort those (using priority queue) by their quality where highest is on top
        // 
        // by doing this, you can get rid of the highest quality guy since he's the one 
        // driving the whole ratio up.
        //
        // to calculate the total wages, you take the highest wage:quality guy, and multiply
        // that by the total quality... idk why lol
        
        // wait i actually understand now, watch https://www.youtube.com/watch?v=o8emK4ehhq0 
        
        vector<vector<double>> sorted;
        priority_queue<int> pq;
        double res = DBL_MAX, totalQ;
        
        for(int i = 0; i < quality.size(); i++) {
            sorted.push_back({(double)(wage[i])/quality[i], (double)quality[i]});
        }
        
        sort(sorted.begin(), sorted.end());
        
        for(auto e : sorted) {
            totalQ += e[1];
            pq.push(e[1]);
            if(pq.size() > k) totalQ -= pq.top(), pq.pop();
            if(pq.size() == k) res = min(res, e[0]*totalQ);
        }
        
        return res;
    }
};
