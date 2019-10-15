type Trie struct {
    next map[rune]*Trie
    isWord bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
    t := Trie{
        next: make(map[rune]*Trie),
        isWord: false,
    }
    return t
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    for _, c := range word {
        if _, ok := this.next[c]; !ok {
            this.next[c] = &Trie{next: make(map[rune]*Trie), isWord: false}
        }
        this = this.next[c]
    }
    this.isWord = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    for _, c := range word {
        if _, ok := this.next[c]; !ok {
            return false
        }
        this = this.next[c]
    }
    return this.isWord
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    for _, c := range prefix {
        if _, ok := this.next[c]; !ok {
            return false
        }
        this = this.next[c]
    }
    return this != nil
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
