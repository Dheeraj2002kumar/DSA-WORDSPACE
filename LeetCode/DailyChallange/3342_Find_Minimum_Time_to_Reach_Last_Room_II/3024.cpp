class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool valid = (nums[0] + nums[1] > nums[2]) &&
                    (nums[0] + nums[2] > nums[1]) &&
                    (nums[1] + nums[2] > nums[0]);

        if (!valid){
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        } 
        else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]){
            return "scalene";
        }

        return "isosceles";
    }
};

/*
# 3024. Type of Triangle


# Intuition

The problem is about determining the **type of triangle** based on the lengths of its three sides. The first idea that comes to mind is to:

* **First validate** whether the three sides can actually form a triangle using the **triangle inequality theorem**.
* Then, if it's a valid triangle, classify it as:

  * **Equilateral** (all sides equal),
  * **Isosceles** (any two sides equal), or
  * **Scalene** (all sides different).

# Approach

1. **Check Triangle Validity**:
   Use the triangle inequality rule:

   * The sum of the lengths of any two sides must be greater than the length of the third side.
   * If not, return `"none"`.

2. **Check for Equilateral**:

   * If all three sides are equal, return `"equilateral"`.

3. **Check for Scalene**:

   * If all three sides are different, return `"scalene"`.

4. **Else**:

   * If exactly two sides are equal, return `"isosceles"`.

# Complexity

* **Time complexity**:
  $O(1)$
  Only a constant number of comparisons are made regardless of input size.

* **Space complexity**:
  $O(1)$
  No extra space is used.

# Code
```cpp []
class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool valid = (nums[0] + nums[1] > nums[2]) &&
                    (nums[0] + nums[2] > nums[1]) &&
                    (nums[1] + nums[2] > nums[0]);

        if (!valid){
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        } 
        else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]){
            return "scalene";
        }

        return "isosceles";
    }
};
```
*/
