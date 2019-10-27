package main

type Trie struct {
	next   map[rune]*Trie
	isWord bool
}

func NewTrie() Trie {
	return Trie{
		next:   make(map[rune]*Trie),
		isWord: false,
	}
}

func (t *Trie) add(word string) {
	for _, c := range word {
		if _, ok := t.next[c]; !ok {
			t.next[c] = &Trie{next: make(map[rune]*Trie), isWord: false}
		}
		t = t.next[c]
	}
	t.isWord = true
}

func longestWord(words []string) string {
	t := NewTrie()
	for _, word := range words {
		t.add(word)
	}

	// check each word
	var ret string
	var flag bool
    var this *Trie
	for _, word := range words {
        this = &t
		flag = false
		for _, c := range word {
			if _, ok := this.next[c]; !ok {
				flag = true
				break
			} else {
				if !this.next[c].isWord {
					flag = true
					break
				}
			}
            this = this.next[c]
		}
		if !flag && len(word) >= len(ret) {
            if len(word) == len(ret) {
                if word < ret {
                    ret = word    
                }
            }else {
                ret = word
            }
		}
	}
	return ret
}

