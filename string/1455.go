type Trie struct{
    isWord bool
    next map[byte]*Trie
}

func constructor() Trie {
    return Trie{false, make(map[byte]*Trie)}
}

func (this *Trie) add(word string) {
    for i := 0; i < len(word); i++ {
        if _, ok := this.next[word[i]]; !ok {
            this.next[word[i]] = &Trie{false, make(map[byte]*Trie)}
        }
        this = this.next[word[i]]
    }
    this.isWord = true
}

func (this *Trie) search(prefix string) bool {
    for i := 0; i < len(prefix); i++ {
        if _, ok := this.next[prefix[i]]; !ok {
            return false
        }
        this = this.next[prefix[i]]
    }
    return true
}
func isPrefixOfWord(sentence string, searchWord string) int {
    words := strings.Split(sentence, " ")
    trie := constructor()
    var ret int
    for _, word := range words {
        trie.add(word)
        ret++
        if trie.search(searchWord) {
            return ret
        }
    }
    return -1
}
