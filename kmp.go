package main

import (
	"fmt"
)

func strStr(haystack string, needle string) int {
	if needle == "" {
		return 0
	}
	prefixTable := getPrefixTable(needle)
	var j int
	for i := 0; i < len(haystack); {
		if haystack[i] == needle[j] {
			// 匹配, 查下一个
			j++
			i++
		} else {
			if j > 0 {
				//不匹配, 尝试前一个prefix
				j = prefixTable[j-1]
			} else {
				i++
			}
		}
		if j == len(needle) {
			//找到匹配
			return i - j + 1
		}
	}
	return -1
}

//自身做一次kmp匹配
func getPrefixTable(s string) []int {
	l := make([]int, len(s))
	var j int
	for i := 1; i < len(s); {
		if s[i] == s[j] {
			//有匹配该位置匹配值+1
			l[i] = j + 1
			j++
			i++
		} else {
			if j > 0 {
				//无匹配缩小j到前一个值
				j = l[j-1]
			} else {
				i++
			}
		}
	}
	return l
}

func main() {
	source := "mississippi"
	target := "issip"
	index := kmp(source, target)
	fmt.Println("match at ", index)
	fmt.Println("match ", source[index:index+len(target)])
}
