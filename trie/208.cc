class Trie {
struct TrieNode {
    std::unordered_map<char, TrieNode*> next;
    bool isWord;
};
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = root;
        for (const auto &c : word) {
            auto iter = cur->next.find(c);
            if (iter == cur->next.end()) {
                cur->next[c] = new TrieNode();
            }
            cur = cur->next[c];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = root;
        for (const auto &c : word) {
            auto iter = cur->next.find(c);
            if (iter == cur->next.end()) {
                return false;
            }
            cur = cur->next[c];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = root;
        for (const auto &c : prefix) {
            auto iter = cur->next.find(c);
            if (iter == cur->next.end()) {
                return false;
            }
            cur = cur->next[c];
        }
        return true;        
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
