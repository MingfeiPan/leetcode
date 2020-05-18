import java.util.HashMap;
import java.util.Map;

class Trie {

    public boolean isWord;
    public Map<Character, Trie> map;
    /** Initialize your data structure here. */
    public Trie() {
        this.isWord = false;
        this.map = new HashMap<>();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Map<Character, Trie> cur = this.map;
        for (int i = 0; i < word.length(); i++) {
            if (!cur.containsKey(word.charAt(i))) {
                cur.put(word.charAt(i), new Trie());
            }
            cur = cur.get(word.charAt(i));
        }
        cur.isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Map<Character, Trie> cur = this.map;
        for (int i = 0; i < word.length(); i++) {
            if (!cur.containsKey(word.charAt(i))) {
                return false;
            }
            cur = cur.get(word.charAt(i));
        }
        return cur.isWord;    
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Map<Character, Trie> cur = this.map;
        for (int i = 0; i < word.length(); i++) {
            if (!cur.containsKey(word.charAt(i))) {
                return false;
            }
            cur = cur.get(word.charAt(i));
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
