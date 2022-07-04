class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // defintely depth first search
        // ... jk it's breadth first,,, sad
        
        // create graph adjacency list graph 
        // each index is a course, and each course/list item has a list of courses that it's a prereq for
        
        // compute indegree for each course
        // a list where each index is a course, and each course/ list item has the number of prereqs it needs
        
        // push all 0 prereq courses onto queue
        
        // pop queue n add to res vector
        // check all items in adjacency its list graph and decrement their indegree
        // add that item to the queue if it's 0 after being decremented
        
        // repeat above til queue is empty
        
        // return res if it's size equals the number of courses
        // else return empty list (not all the courses were able to be taken)
        
        vector<vector<int>> adjG(numCourses);
        vector<int> prereqNums(numCourses, 0);
        
        for(auto e : prerequisites) {
            adjG[e[1]].push_back(e[0]);
            prereqNums[e[0]]++;
        }
        
        queue<int> q;
        vector<int> res;
        
        for(int i = 0; i < prereqNums.size(); i++)
            if(prereqNums[i] == 0) q.push(i);
        
        while(!q.empty()) {
            int curr = q.front();
            res.push_back(curr);
            q.pop();
            
            for(auto course : adjG[curr])
                if(--prereqNums[course] == 0) q.push(course);
        }

        if(res.size() == numCourses) return res;
        return {};
    }
};
