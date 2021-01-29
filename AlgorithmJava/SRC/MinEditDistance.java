import java.io.*;
import java.util.*;

class MinEditDistance
{
    static int min(int x, int y, int z)
    {
        if (x <= y && x <= z)
        {
            return x;
        }

        if (y <= x && y <= z)
        {
            return y;
        }
        else
        {
            return z;
        }
    }
    
    /// Recursive
    static int editDist(String str1, String str2, int m, int n)
    {
        if (m == 0)
        {
            return n;
        }

        if (n == 0)
        {
            return m;
        }

        if (str1.charAt(m - 1) == str2.charAt(n - 1))
        {
            return editDist(str1, str2, m - 1, n - 1);
        }

        int minVal = min(
                  editDist(str1, str2, m,     n - 1), // Insert
                  editDist(str1, str2, m - 1, n    ), // Remove
                  editDist(str1, str2, m - 1, n - 1) // Replace
                    );

        return 1 + minVal;
    }

    /// table 
    static int dp(String str1, String str2, int m, int n)
    {
      int dp[][] = new int[m + 1][n + 1];

      for(int i = 0; i <= m; i++)
      {
        for(int j = 0; j <= n; j++)
        {
          if (i == 0)
          {
            dp[i][j] = j;
          }
          else if (j == 0)
          {
            dp[i][j] = i;
          }     
          else if (str1.charAt(i - 1) == str2.charAt(j - 1))
          {
            dp[i][j] = dp[i - 1][j - 1];
          }
          else
          {
            int minVal = min(dp[i][j - 1], // Insert
                             dp[i - 1][j], // Remove
                             dp[i - 1][j - 1]); // Replace
            dp[i][j] = 1 + minVal;
          }
        }

        for(int a = 0; a <= m; a++)
        {
            for(int b = 0; b <= n; b++)
            {
                System.out.print(String.format("%2d", dp[a][b]) + " ");
            }
            System.out.println("");
        }
        System.out.println("====================================================");
      }
      return dp[m][n];
    }

    public static void main(String args[])
    {
        String str1 = "sunday";
        String str2 = "saturday";
        //System.out.println(editDist(str1, str2, str1.length(), str2.length()));
        System.out.println(dp(str1, str2, str1.length(), str2.length()));
    }
}
