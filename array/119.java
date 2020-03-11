class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> upperRow = new ArrayList<>();
        upperRow.add(1);
        
        if (rowIndex == 0) {
            return upperRow;
        }
        List<Integer> lowerRow = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        upperRow.add(1);
        lowerRow.add(1);
        lowerRow.add(1);
        
        int index = 2;
        while (index <= rowIndex) {
            upperRow.clear();
            upperRow.add(1);
            for (int i = 1; i < index; i++) {
                upperRow.add(lowerRow.get(i-1) + lowerRow.get(i));
            }
            upperRow.add(1);
            System.out.println(upperRow);
            temp = lowerRow;
            lowerRow = upperRow;
            upperRow = temp;
            index++;
        }
        return lowerRow;
    }
}
