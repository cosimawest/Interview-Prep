class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman Ford's Algorithm
        
        // set value of every point except start to infinity
        vector<int> c(n, INT_MAX);
        c[src] = 0;
        
        // relax each edge k+1 times (+1 bc k = transfers not flights)
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: flights)
                if(c[e[0]] != INT_MAX)
                    // relax destination point (min between it's val and sum of src + edge's price)
                    // C and c so that that round's relaxation doesn't interfere
                    C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[dst] == INT_MAX ? -1 : c[dst];
    }
};
