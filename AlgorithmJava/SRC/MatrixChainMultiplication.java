/* A naive recursive implementation that simply follows 
   the above optimal substructure property */
class MatrixChainMultiplication { 

    /// exponential 
    // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
    static int MatrixChainOrder(int p[], int i, int j) 
    { 
        if (i == j)
        {
            return 0; 
        }

        int min = Integer.MAX_VALUE; 
        // place parenthesis at different places between 
        // first and last matrix, recursively calculate 
        // count of multiplications for each parenthesis 
        // placement and return the minimum count 
        for (int k = i; k < j; k++)  
        {
            int count = MatrixChainOrder(p, i, k) 
                        + MatrixChainOrder(p, k + 1, j) 
                        + p[i - 1] * p[k] * p[j]; 
  
            if(count < min)
            {
                min = count; 
            } 
        }
  
        // Return minimum count 
        return min; 
    } 
  
    /**
        Time Complexity: O(n3 )
        Auxiliary Space: O(n2)
     */
    // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
    static int MatrixChainOrder(int p[], int n) 
    { 
        /* For simplicity of the  
        program, one extra row and 
        one extra column are allocated in m[][].  0th row 
        and 0th column of m[][] are not used */
        int m[][] = new int[n][n]; 
  
        int i, j, k, L, q; 
  
        /* m[i, j] = Minimum number of scalar 
        multiplications needed to compute the matrix 
        A[i]A[i+1]...A[j] = A[i..j] where 
        dimension of A[i] is p[i-1] x p[i] */
  
        // cost is zero when multiplying one matrix. 
        for (i = 1; i < n; i++)
        {
            m[i][i] = 0; 
        }

        // L is chain length. 
        for (L = 2; L < n; L++)  
        { 
            for (i = 1; i < n - L + 1; i++)  
            { 
                j = i + L - 1; 
                if (j == n)
                {
                    continue; 
                }

                m[i][j] = Integer.MAX_VALUE; 
                for (k = i; k <= j - 1; k++)  
                { 
                    // q = cost/scalar multiplications 
                    q = m[i][k] + m[k + 1][j] 
                        + p[i - 1] * p[k] * p[j]; 
                    if (q < m[i][j])
                    { 
                        m[i][j] = q; 
                    } 
                }
            } 
        } 
  
        return m[1][n - 1]; 
    } 

    /**
    Time Complexity : O(n2)
     */
    static int MatrixChainOrder2(int p[], int n) 
    { 
      
        /* For simplicity of the program, one extra row and one extra column are 
        allocated in dp[][]. 0th row and 0th column of dp[][] are not used */
        int [][]dp=new int[n][n]; 
      
        /* dp[i, j] = Minimum number of scalar multiplications needed to compute the matrix M[i]M[i+1]...M[j]  
                    = M[i..j] where dimension of M[i] is p[i-1] x p[i] */
                      
        // cost is zero when multiplying one matrix. 
        for (int i=1; i<n; i++)
        {
            dp[i][i] = 0; 
        }

        // Simply following above recursive formula. 
        for (int L=1; L<n-1; L++)  
        {
            for (int i=1; i<n-L; i++)      
            {
              dp[i][i+L] = Math.min(dp[i+1][i+L] + p[i-1]*p[i]*p[i+L], 
                        dp[i][i+L-1] + p[i-1]*p[i+L-1]*p[i+L]);      
            }
        }
        return dp[1][n-1]; 
    } 

    
    // Driver code 
    public static void main(String args[]) 
    { 
        //int arr[] = new int[] { 1, 2, 3, 4, 3, 5, 6, 10, 5, 6, 8, 15, 20, 5, 3, 7, 9, 50, 40, 32, 46}; /// 21
        int arr[] = new int[] { 1, 2, 3, 4, 3, 5, 6, 10, 5, 6, 8, 15, 20, 5, 3, 7, 9, 50, 40, 32, 46, 80}; /// 22
        int n = arr.length; 
  
        long time = System.currentTimeMillis();

        // System.out.println( 
        //     "Minimum number of multiplications of Method 1 is "
        //     + MatrixChainOrder(arr, 1, n - 1)); 

        // System.out.println( 
        //     "Execute Time of Method 1 is "
        //     + (System.currentTimeMillis() - time)); 

        time = System.currentTimeMillis();
        System.out.println( 
            "Minimum number of multiplications of Method 2 is "
            + MatrixChainOrder(arr, n)); 

        System.out.println( 
            "Execute Time of Method 2 is "
            + (System.currentTimeMillis() - time)); 

        time = System.currentTimeMillis();
        System.out.println( 
            "Minimum number of multiplications of Method 3 is "
            + MatrixChainOrder2(arr, n)); 

        System.out.println( 
            "Execute Time of Method 3 is "
            + (System.currentTimeMillis() - time)); 
    } 
} 