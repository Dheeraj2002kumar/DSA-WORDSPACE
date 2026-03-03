public class search_row_col_sorted_arr {
    public static boolean matSearch(int mat[][], int x) {
        // your code here
        int n = mat.length, m = mat[0].length;
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (mat[row][col] == x) {
                return true; 
            }else if (mat[row][col] < x) {
                row++; 
            }else {
                col--;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        // Sample matrix
        int[][] mat = {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {27, 29, 37, 48},
            {32, 33, 39, 50}
        };

        // Test values to search for
        int x = 29;
        boolean result = matSearch(mat, x);

        // Output the result
        if (result) {
            System.out.println("Element " + x + " found in the matrix.");
        } else {
            System.out.println("Element " + x + " not found in the matrix.");
        }

        // Test with another value
        x = 100;
        result = matSearch(mat, x);

        if (result) {
            System.out.println("Element " + x + " found in the matrix.");
        } else {
            System.out.println("Element " + x + " not found in the matrix.");
        }
    }
}
