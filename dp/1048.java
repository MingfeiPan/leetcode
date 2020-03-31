class Solution {
    public int longestStrChain(String[] words) {
        // 按string length构造dp, 查询每个word的sub word length, 当前word的length
        // 为sub word length+1。遍历所有word即可找到最大长度
        int ret = 0;
        Arrays.sort(words, new Comparator<String>(){
            public int compare(String s1, String s2) {
                return s1.length() - s2.length();
            }
        });
        Map<String, Integer> dp = new HashMap<>();
        for (String word : words) {
            int cur = 0;
            for (int i = 0; i < word.length(); i++) {
                String pre = word.substring(0, i) + word.substring(i+1);
                cur = Math.max(cur, dp.getOrDefault(pre, 0)+1);
            }
            dp.put(word, cur);
            ret = Math.max(ret, cur);
        }
        return ret;
    }
}
