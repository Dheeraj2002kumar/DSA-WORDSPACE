class Solution {
    using Matrix = array<array<int,26>,26>;
    int MOD = 1e9+7;

    inline Matrix matrixMultiplication(Matrix& A,Matrix& B){
        Matrix res{};
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                for(int k=0;k<26;++k){
                    res[i][j] = (res[i][j] + (1LL*A[i][k]*B[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    inline Matrix matrixExponentiation(Matrix& transformation_matrix,int t){
        Matrix res{};
        //Create identity matrix (to multiply)
        for(int i=0;i<26;++i)
            res[i][i] = 1;
        
        while(t){
            if(t&1)
                res = matrixMultiplication(transformation_matrix,res);
            
            //Square the base & half the exponent
            transformation_matrix = matrixMultiplication(transformation_matrix,transformation_matrix);
            t /= 2;
        }
        return res;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        array<int,26> intial_freq{};
        for(char c: s)
            intial_freq[c-'a']++;

        Matrix transformation_matrix{};
        for(int i=0;i<26;++i){
            //Update column for each transformation
            for(int j=i+1; j<=i+nums[i]; ++j)
                transformation_matrix[j%26][i]++;
        }

        Matrix res = matrixExponentiation(transformation_matrix,t);
        //Now calculate res*intial_freq
        array<int,26> final_array{};
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j)
                final_array[i] = (final_array[i] + (1LL*res[i][j]*intial_freq[j])% MOD) % MOD;
        }

        int string_size = 0;
        for(int i=0;i<26;++i)
            string_size = (string_size + final_array[i]) % MOD;
        
        return string_size;
    }
};


/*

# Intuition

The problem involves simulating a transformation process on a string composed of lowercase letters. Each character can transform into others in a specific pattern defined by an input vector. Since applying the transformation naively `t` times would be too slow, matrix exponentiation provides an efficient way to compute the result after `t` transformations.

The key insight is to treat the frequency of each character in the string as a vector, and the transformation rules as a matrix. Repeated transformations correspond to raising the matrix to the power `t` and applying it to the initial frequency vector.

---

# Approach

1. **Character Frequency Vector**: First, compute the frequency of each character in the initial string and store it in an array of size 26.

2. **Build Transformation Matrix**: Construct a 26×26 matrix where each column represents how a character at that index can transform into others based on the `nums` array. For each character `i`, it can transform into the next `nums[i]` characters (modulo 26).

3. **Matrix Exponentiation**: To compute the result of applying the transformation `t` times, raise the transformation matrix to the power of `t` using binary exponentiation.

4. **Apply Matrix to Frequency Vector**: Multiply the resulting matrix with the initial frequency vector to get the final frequency of characters after all transformations.

5. **Compute Final Length**: Sum up the values in the resulting frequency vector to get the final string length after `t` transformations.

---

# Complexity

* **Time complexity**:
  $O(26^3 \cdot \log t)$

  * Matrix multiplication takes $O(26^3)$.
  * Matrix exponentiation takes $O(\log t)$ multiplications.

* **Space complexity**:
  $O(26^2)$

  * For storing matrices and frequency vectors.

*/
