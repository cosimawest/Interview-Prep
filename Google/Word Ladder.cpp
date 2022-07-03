class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // tip: uncomment the couts for a better understanding of how this algo works
        // shortest sequence => breadth first search
        
        // first make sure endWord is in wordList
        set<string> baseCase;
        for(auto word : wordList) baseCase.insert(word);
        
        if(!baseCase.count(endWord)) return 0;
        
        // then create a set for visited, and a queue for transformed words
        set<string> visited;
        queue<string> q;
        
        // put beginWord in visted set and word queue
        visited.insert(beginWord);
        q.push(beginWord);
        int count = 1;
        
        // loop through wordList
        // add to queue if it's a transformation for the current word in queue
        // add to set if it has been added to the queue at one point
        // add to count after every iteration of wordList bc with every iteration there should
        // be at least one word added to the queue 
        // (if there's not then count doesn't really matter bc the queue will empty before 
        // we get to endWord, and we'll just return 0)
        
        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0; k < sz; k++) {
                //cout << "front of the queue: " << q.front() << endl;
                string s = q.front(), t;
                if(s == endWord) return count;
                //cout << "doesn't equal " << endWord << endl;
                q.pop();
                for(int i = 0; i < s.size(); i++) {
                    t = s;
                    for(char j = 'a'; j <= 'z'; j++) {
                        t[i] = j;
                        //cout << "seeing if " << t << " is in the set" << endl;
                        // if the tranformation is valid, and not already visited
                        if(baseCase.count(t) && !visited.count(t)) {
                            visited.insert(t);
                            q.push(t);
                            //cout << "added " << t << " to visited and queue" << endl;
                        }   
                    }
                }
            }
            //cout << "count has been incremeted through purging of the current queue level of " << sz << endl << endl;
            count++;
        }
        
        return 0;
        
        // big O: O(m^2*n) woah...
        
        // okay now let's code so I can read more of tomodachi game!!!
        
        
    }
};
