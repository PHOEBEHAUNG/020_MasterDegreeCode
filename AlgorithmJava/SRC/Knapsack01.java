// { Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Item 
{
    int value, weight;
    Item(int x, int y)
    {
        this.value = x;
        this.weight = y;
    }
}

class Knapsack01 
{   
    /// input : 
    /// https://openhome.cc/Gossip/AlgorithmGossip/KnapsackProblem.htm
    // 0	李子	4KG	NT$4500
    // 1	蘋果	5KG	NT$5700
    // 2	橘子	2KG	NT$2250
    // 3	草莓	1KG	NT$1100
    // 4	甜瓜	6KG	NT$6700

    // w 8kg
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
        System.out.println(String.format("Count : %d", t));
		while(t-- > 0)
        {
            String inputLine[] = br.readLine().trim().split(" ");
            /// 有n種物品
            int n = Integer.parseInt(inputLine[0]);
            ///最大重量 w
            int w = Integer.parseInt(inputLine[1]);
            Item[] arr = new Item[n];
            inputLine = br.readLine().trim().split(" ");
            /// 逐一輸入 value weight
            for(int i = 0, k = 0; i < n; i++)
            {
                arr[i] = new Item(Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]));
            }
            System.out.println(String.format("%.2f", new Solve().fractionalKnapsack(w, arr, n)));
        }
    }
}// } Driver Code Ends


/*
class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}
*/

/// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
class Solve
{
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        // Your code here
        int[] values = new int[W + 1]; 
        
        int TempMax = 0;
        int TempValue = 0;

        for(int i = 0; i <= W; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[j].weight <= i)
                {
                    TempValue = arr[j].value + values[i - arr[j].weight];
                    TempMax = Math.max(TempValue, TempMax);
                }
            }
            System.out.println("[CK] The max value of " + i + " kg is " + TempMax);
            values[i] = TempMax;
        }

        return values[W];
    }
}