class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        low, mid, high = 0, 0, len(nums) - 1
        
        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:  # nums[mid] == 2
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1

/*

# Intuition
The problem requires us to sort an array containing only the integers 0, 1, and 2, in-place and using constant space. The first thought is to avoid using any built-in sort functions and instead find a way to organize these three values efficiently.

Since there are only three distinct elements, we can solve this with a single pass through the list using a strategy inspired by the Dutch National Flag problem. The idea is to categorize the numbers into three regions — low (0s), mid (1s), and high (2s) — and move elements into their appropriate regions as we scan the array.

# Approach
We maintain three pointers:
- `low`: the next position to place 0
- `mid`: the current element under consideration
- `high`: the next position to place 2

We traverse the list with `mid`:
- If `nums[mid]` is 0: we swap it with `nums[low]`, and move both `low` and `mid` forward.
- If `nums[mid]` is 1: we just move `mid` forward.
- If `nums[mid]` is 2: we swap it with `nums[high]` and move `high` backward (we don’t move `mid` forward in this case because the swapped value needs to be examined).

This approach ensures that all 0s are moved to the front, all 2s to the back, and 1s remain in the middle, completing the sort in a single pass.

# Complexity
- Time complexity:  
  $$O(n)$$  
  We make a single pass through the list, examining each element at most once.

- Space complexity:  
  $$O(1)$$  
  We use only a constant amount of additional space (three pointers).

# Code
```python3 []
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        low, mid, high = 0, 0, len(nums) - 1
        
        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:  # nums[mid] == 2
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1

            
```

*/
