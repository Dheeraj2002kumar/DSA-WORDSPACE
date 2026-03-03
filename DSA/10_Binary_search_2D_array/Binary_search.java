class Binary_search {
    
    public boolean searchMatrix(int[][] matrix, int target) {
        int N = matrix.length;      
        int M = matrix[0].length;   
        int row_index, col_index;
        int start = 0, end = N * M - 1, mid;

        
        while (start <= end) {
            mid = start + (end - start) / 2;
            row_index = mid / M;       // Calculate the row index
            col_index = mid % M;       // Calculate the column index

            if (matrix[row_index][col_index] == target) {
                return true;
            }
            else if (matrix[row_index][col_index] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    
    public static void main(String[] args) {
        Binary_search solution = new Binary_search();

        // Test matrix
        int[][] matrix = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 60}
        };

        // Test case 1: Searching for target 3 (should return true)
        int target1 = 3;
        System.out.println("Search for " + target1 + ": " + solution.searchMatrix(matrix, target1));

        // Test case 2: Searching for target 13 (should return false)
        int target2 = 13;
        System.out.println("Search for " + target2 + ": " + solution.searchMatrix(matrix, target2));

        // Test case 3: Searching for target 23 (should return true)
        int target3 = 23;
        System.out.println("Search for " + target3 + ": " + solution.searchMatrix(matrix, target3));
    }
}