/// Hamiltonian Cycle | Backtracking-6
class HamiltonianCycle 
{ 
    final int V = 5; 
    int path[]; 
  
    boolean isSafe(int v, int graph[][], int path[], int pos) 
    { 
      if (graph[path[pos - 1]][v] == 0)
      {
        return false; 
      }
      for (int i = 0; i < pos; i++) 
      {
        if (path[i] == v) 
        {        
          return false; 
        }
      }
      return true; 
    } 
  
    boolean hamCycleUtil(int graph[][], int path[], int pos) 
    { 
      System.out.println("hamCycleUtil Start");
      /// 每個點都拜訪過後
      if (pos == V) 
      {  
        /// 若最後一點和第一點相同
        if (graph[path[pos - 1]][path[0]] == 1) 
        {
          return true; 
        }  
        else
        {
          return false; 
        } 
      }
      
      /// bottom up solution
      for (int v = 1; v < V; v++) 
      { 
        System.out.println("Bottom-Up Solution Index : " + v);
        /// 和Path最後一點是否相鄰，是否已經包含在路徑
        if (isSafe(v, graph, path, pos)) 
        { 
          path[pos] = v; 
          System.out.println("Add Vertex : " + path[pos]);
          /* recur to construct rest of the path */
          if (hamCycleUtil(graph, path, pos + 1) == true) 
          {
            System.out.println("Add Vertex Return : " + path[pos]);
            return true; 
          }
          path[pos] = -1; 
        } 
      } 
      return false; 
    } 
  
    int hamCycle(int graph[][])
    { 
      path = new int[V]; 
      for (int i = 0; i < V; i++)
      {
        path[i] = -1; 
      }
      
      path[0] = 0; 
      if (hamCycleUtil(graph, path, 1) == false) 
      { 
        System.out.println("\nSolution does not exist"); 
        return 0; 
      } 
  
      printSolution(path); 
      return 1; 
    } 
  
    void printSolution(int path[]) 
    { 
      System.out.println("Solution Exists: Following is one Hamiltonian Cycle"); 
      for (int i = 0; i < V; i++) 
      {      
        System.out.print(" " + path[i] + " "); 
      }
      System.out.println(" " + path[0] + " "); 
    } 
  
    public static void main(String args[]) 
    { 
      HamiltonianCycle hamiltonian = new HamiltonianCycle(); 
      /* Let us create the following graph 
        (0)--(1)--(2) 
         |   / \   | 
         |  /   \  | 
         | /     \ | 
        (3)-------(4)    */
      int graph1[][] = {
            {0, 1, 0, 1, 0}, 
            {1, 0, 1, 1, 1}, 
            {0, 1, 0, 0, 1}, 
            {1, 1, 0, 0, 1}, 
            {0, 1, 1, 1, 0}, 
        }; 

      System.out.println("=======================================================");
      // Print the solution 
      hamiltonian.hamCycle(graph1); 
  
      /* Let us create the following graph 
         (0)--(1)--(2) 
          |   / \   | 
          |  /   \  | 
          | /     \ | 
         (3)       (4)    */
      int graph2[][] = {{0, 1, 0, 1, 0}, 
            {1, 0, 1, 1, 1}, 
            {0, 1, 0, 0, 1}, 
            {1, 1, 0, 0, 0}, 
            {0, 1, 1, 0, 0}, 
        }; 
  
      System.out.println("=======================================================");
      // Print the solution 
      hamiltonian.hamCycle(graph2); 
    } 
} 