// Given an array of positive number, calculate the number of possible contiguous subarrays having product lesser than a given number k
// input: arr[] = [1, 2, 3, 4]
//          k = 10
// output: 7
// The subarrays are {1}, {2}, {3}, {4}, {1, 2}, {1, 2, 3} and {2, 3}

public class SubArray {
    int SubArrayFind(int arr[], int k){
        int count = 0;
        int product = 1;
        int left = 0;

        for (int right = 0; right < arr.length; right++) {
            product *= arr[right];
            System.out.println("Product : " + product);

            while (product >= k && left <= right) {
                product /= arr[left];
                left++;
                System.out.println("\nProduct and left : " + product + " " + left);
            }

            count += right - left + 1;

            System.out.println("Count of number " + count);
        }

        return count;
    }


    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4};
        int k = 10;

        SubArray subArray = new SubArray();
        int result = subArray.SubArrayFind(arr, k);
        System.out.println(result);
    }
}