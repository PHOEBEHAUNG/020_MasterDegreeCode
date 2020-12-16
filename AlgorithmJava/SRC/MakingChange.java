// { Driver Code Starts
//Initial Template for Java

/// https://practice.geeksforgeeks.org/problems/coin-change2448/1
import java.io.*;
import java.util.*;
class MakingChange
{
  public static void main(String args[])
  {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while(t-- > 0)
    {
      /// n dollor
      /// m coins 
      int n = sc.nextInt();
      int m = sc.nextInt();
      int arr[] = new int[m];
      for(int i = 0;i < m; i++)
      {
        arr[i] = sc.nextInt(); /// coin value
      }

      Solution ob = new Solution();
      System.out.println(ob.count(arr, m, n));
    }
  }
}// } Driver Code Ends


//User function Template for Java
class Solution
{
  /// return how many sub-set for making change? 
  public long count(int coins[], int coinType, int dollor) 
  {
    //code here.
    int[] dp = new int[dollor + 1];   /// 用一種硬幣有幾種選擇
    dp[0] = 1;

    for (int j = 0; j < coinType; j++) 
    {
      for (int i = coins[j]; i <= dollor; i++) 
      {
        dp[i] = dp[i] + dp[i - coins[j]];
      }
    }

    // for (int coin : coins) 
    // {
    //   for (int i = coin; i <= dollor; i++) 
    //   {
    //     dp[i] += dp[i-coin];
    //   }
    // }
    return dp[dollor];
  } 
}