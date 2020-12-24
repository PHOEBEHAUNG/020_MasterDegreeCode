import java.io.*;
import java.util.*;
/// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
class LongestCommonSubsequence
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
		int test=sc.nextInt();
		while(test-- > 0)
    {
		    int p=sc.nextInt();             // Take size of both the strings as input
		    int q=sc.nextInt();
		    String s1=sc.next();            // Take both the string as input
	      String s2=sc.next();
		    Solution obj = new Solution();
		    // System.out.println(obj.LongestCommonSubsequenceCount_Method1(p, q, s1, s2));
		    System.out.println(obj.LongestCommonSubstring_Method2(p, q, s1, s2));

        // int p=sc.nextInt();
		    // String s1=sc.next();    
		    // Solution obj = new Solution();
        // System.out.println(obj.LongestCommonIncreasingSubsequence_Method2(p, s1));
		}
  }
}

class Solution
{
  /// 獲得最長長度
  /**
  *                           lcs("AXYT", "AYZX")
  *                       /                 
  *         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
  *         /                              /               
  * lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
  */
  /// 時間複雜度 O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.
  public long LongestCommonSubsequenceCount_Method1(int p, int q, String s1, String s2) 
  {
    if(p == 0 || q == 0)
    {
      return 0;
    }
    else if (s1.charAt(p - 1) == (s2.charAt(q - 1)))
    {
      return 1 + LongestCommonSubsequenceCount_Method1(p - 1, q - 1, s1, s2);
    }
    else
    {
      return Math.max(LongestCommonSubsequenceCount_Method1(p, q - 1, s1, s2), LongestCommonSubsequenceCount_Method1(p - 1, q, s1, s2)) ;
    }
  }

  /// 表格式 
  /// 時間複雜度 O(mn) 
  /// 空間複雜度為 O(mn) /// 可優化空間複雜度為 O(n)
  public long LongestCommonSubsequenceCount_Method2(int p, int q, String s1, String s2) 
  {
    int[][] table = new int[p + 1][q + 1]; 

    for(int i = 1; i <= p; i++)
    {
      for(int j = 1; j <= q; j++)
      {
        if(s1.charAt(i - 1) == s2.charAt(j - 1))
        {
          table[i][j] = table[i - 1][j - 1] + 1;
        }
        else
        {
          table[i][j] = Math.max(table[i - 1][j], table[i][j - 1]);
        }
      }
    }
    
    /// print the longest Subsequence
    int lengh = 0;
    for(int i = 1; i <= p; i++)
    {
      for(int j = 1; j <= q; j++)
      {
        if((table[i][j] != table[i - 1][j - 1]) && lengh < table[i][j])
        {
          System.out.print(s1.charAt(i - 1));
          lengh++;
        }
      }
    }
    System.out.println("");
    return table[p][q];
  }

  /// Needleman-Wunsch Algorithm
  /// 去頭去尾
  /// p : s1 長度
  /// q : s2 長度
  public int LongestCommonSubsequence_NeedlemanWunsch() 
  {
    
    return 0;
  } 

  /*
    Optimal Substructure: 
    Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i 
    such that arr[i] is the last element of the LIS.

    L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; 
    or
    L(i) = 1, if no such j exists.

    Input  : arr[] = {3, 10, 2, 11}
    f(i): Denotes LIS of subarray ending at index ‘i’

    (LIS(1)=1)

          f(4)  {f(4) = 1 + max(f(1), f(2), f(3))}
      /    |    \
    f(1)  f(2)  f(3) {f(3) = 1, f(2) and f(1) are > f(3)}
          |      |  \
          f(1)  f(2)  f(1) {f(2) = 1 + max(f(1)}
                  |
                f(1) {f(1) = 1}
  */
  /*
  Complexity Analysis:
  Time Complexity: The time complexity of this recursive approach is exponential as there is a case of overlapping subproblems 
  as explained in the recursive tree diagram above.

  Auxiliary Space: O(1). No external space used for storing values 
  apart from the internal stack space.
  */ 
  int maxLength  = 1;
  int maxEndPos = 0;
  public int LongestCommonIncreasingSubsequence_Method1(int p, String s1)
  {
    if(p == 1)
    {
      return 1;
    }
    else
    {
      int maxEndingTemp   = 1;
      int res = 1;
      for(int i = 1; i < p; i++)
      {
        res = LongestCommonIncreasingSubsequence_Method1(i, s1);

        if(s1.charAt(i - 1) < s1.charAt(p - 1) && maxEndingTemp < res + 1)
        {
          maxEndingTemp = res + 1;
          maxEndPos = i;
        }
      }

      if(maxLength < maxEndingTemp)
      {
        maxLength = maxEndingTemp;
      }

      return maxEndingTemp;
    }
  } 

  /*
  Time Complexity: O(n^2).
  As nested loop is used.
  Auxiliary Space: O(n).
  Use of any array to store LIS values at each index.
  */
  public int LongestCommonIncreasingSubsequence_Method2(int p, String s1) 
  {
    int[] weights = new int[p];

    for(int i = 0; i < p; i++)
    { 
      weights[i] = 1; 
    }
    for(int i = 1; i < p; i++)
    {
      for(int j = 0; j < i; j++)
      {
        if(s1.charAt(i) > s1.charAt(j) && weights[i] < weights[j] + 1)
        {
          weights[i] = weights[j] + 1; /// 前面有幾個比她小的，就會加幾個
        }
      }
    }

    int max = 0;
    for(int i = 0; i < p; i++)
    {
      if(weights[i] > max)
      {
        max = weights[i];
      }
    }

    return max;
  } 

  public long CyclicLongestCommonSubsequence() 
  {
   
    return 0;
  } 

  public long ShortestCommonSupersequence() 
  {
   
    return 0;
  } 

  /// KMP Algorithm for Pattern Searching
  /// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/ 
  public long LongestCommonSubstring_Method1() 
  {

    return 0;
  }

  /// Dynamic Programming
  public long LongestCommonSubstring_Method2(int p, int q, String s1, String s2) 
  {
    int weights[][] = new int[p + 1][q + 1]; 
    int result = 0;  // To store length of the longest common substring 
          
    // Following steps build LCSuff[m+1][n+1] in bottom up fashion 
    for (int i = 0; i <= p; i++)  
    { 
      for (int j = 0; j <= q; j++)  
      { 
        if (i == 0 || j == 0)
        { 
          weights[i][j] = 0; 
        }        
        else if (s1.charAt(i - 1) == s2.charAt(j - 1)) 
        { 
          weights[i][j] = weights[i - 1][j - 1] + 1; 
          result = Integer.max(result, weights[i][j]); 
        }  
        else
        {
          weights[i][j] = 0; 
        }  
      } 
    } 
    return result;
  } 
}