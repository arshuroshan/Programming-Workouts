import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();
        
        if (numRows >= 1) {
            triangle.add(List.of(1));
        }
        
        for (int row = 1; row < numRows; row++) {
            List<Integer> previousRow = triangle.get(row - 1);
            List<Integer> currentRow = new ArrayList<>();
            
            currentRow.add(1);
            
            for (int col = 1; col < previousRow.size(); col++) {
                int sum = previousRow.get(col - 1) + previousRow.get(col);
                currentRow.add(sum);
            }
            
            currentRow.add(1);
            
            triangle.add(currentRow);
        }
        
        return triangle;
    }
}