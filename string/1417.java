class Solution {
    public String reformat(String s) {
        char[] chs = s.toCharArray();
        List<Character> intList = new ArrayList<>();
        List<Character> charList = new ArrayList<>();
        for(char c : chs) {
            if (Character.isDigit(c)) {
                intList.add(c);
            } else {
                charList.add(c);
            }
        }
        int intSize = intList.size();
        int charSize = charList.size();
        if (intSize > charSize) {
            if (intSize - charSize > 1) {
                return "";
            }
            StringBuilder str = new StringBuilder();
            int i = 0;
            int j = 0;
            while (i < intSize && j < charSize) {
                str.append(intList.get(i++));
                str.append(charList.get(j++));
            }          
            str.append(intList.get(i));
            return str.toString();
        }
        if (charSize >= intSize) {
            if (charSize - intSize > 1) {
                return "";
            }
            StringBuilder str = new StringBuilder();
            int i = 0;
            int j = 0;
            while (i < charSize && j < intSize) {
                str.append(charList.get(i++));
                str.append(intList.get(j++));
            }    
            if (i < charSize) {
                str.append(charList.get(i));    
            }
            return str.toString();            
        }
        return "";
    }
}
