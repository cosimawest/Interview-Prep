// this is brilliant and a good intro to Trie

class TrieNode {
public:
    bool is_end;
    vector<TrieNode*> children;
    
    TrieNode() {
        is_end = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
public:
    TrieNode* getRoot() { return root; }
    
    Trie(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++) 
            addWord(words[i]);
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(cur->children[index] == NULL) cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->is_end = true;
    }

private:
    TrieNode* root;
};

class Solution {
public:    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        unordered_set<string> res_set;
    
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                findWord(i, j, "", root, board, res_set);
        
        vector<string> res;
        for(auto word : res_set) res.push_back(word);
        return res;
    }
    
    void findWord(int i,int j,string word,TrieNode* root,vector<vector<char>>& board,unordered_set<string>& res){
        if(i<0||i>=board.size()||j<0||j>=board[0].size() || board[i][j]==' ') return;
        
        if(root->children[board[i][j]-'a'] != NULL) {
            word = word + board[i][j];
            root = root->children[board[i][j]-'a'];
            if(root->is_end) res.insert(word);
            char c = board[i][j];
            board[i][j] = ' ';
            findWord(i+1, j, word, root, board, res);
            findWord(i-1, j, word, root, board, res);
            findWord(i, j+1, word, root, board, res);
            findWord(i, j-1, word, root, board, res);
            board[i][j]=c;  
        }
    }
};
