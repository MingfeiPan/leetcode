package main

import (
	"fmt"
)

func kmp(source, target string) int {
	var curMatch string
	var matchLength int
	curIndex := -1
	for i := 0; i < len(source); {
		for j := 0; j < len(target); {
			if i == len(source) {
				fmt.Println(curMatch)
				//end of source
				return -1
			}
			if source[i] == target[j] {
				curIndex = i
				curMatch += string(target[j])
				//find a match
				if curMatch == target {
					return curIndex - len(target) + 1
				}
				i++
				j++
			} else {
				if curMatch == "" {
					i++
				} else {
					matchLength = findPartialMatch(curMatch)
					fmt.Println(curMatch)
					j -= len(curMatch) - matchLength
					// i += len(curMatch) - matchLength
					curMatch = curMatch[:matchLength]
				}
			}
		}
	}
	return -1
}

func findPartialMatch(s string) int {
	var matchLength int
	for i := 1; i < len(s); i++ {
		if s[0:i] == s[len(s)-i:len(s)] {
			matchLength = i
		}
		//fmt.Println("prefix ", s[0:i])
		//fmt.Println("postfix ", s[len(s)-i:len(s)])
	}
	return matchLength
}

func max(s []int) int {
	max := -1
	for _, v := range s {
		if max < v {
			max = v
		}
	}
	return max
}

func main() {
	source := "bbc abcdab abcdabcdabde"
	target := "abcdabd"
	index := kmp(source, target)
	fmt.Println("match at ", index)
	fmt.Println("match ", source[index:index+len(target)])
}
