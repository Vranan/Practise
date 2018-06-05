/* public class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int[][] havana = new int [A.length][A[0].length];
        
        for (int i = 0; i < A.length; i++) {
            int k = A[0].length;
            for (int j = 0; j < A[0].length; j++) {
                    havana[i][--k] = A[i][j];
                    if (havana[i][k] == 1)
                        havana[i][k] = 0;
                    else if (havana[i][k] == 0)
                        havana[i][k] = 1;
            }
        }
        return havana;
    } */

class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int C = A[0].length;
        int count = 0;
        for (int[] row: A) {
            count++;
            for (int i = 0; i < (C + 1) / 2; ++i) {
                int tmp = row[i] ^ 1;
                row[i] = row[C - 1 - i] ^ 1;
                row[C - 1 - i] = tmp;
            }
        }
        System.out.println("count = " + count);
        return A;
    }
}


public static void main(String[] args) {
    Solution sl = new Solution();
    int[][] exp = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    int[][] havana = sl.flipAndInvertImage(exp);
    System.out.println("Original Array");
    
     /* for (int i = 0; i < exp.length; i++)
     {
        for (int j = 0; j < exp[0].length; j++)
        {
            System.out.print(exp[i][j] + " ");
        }
        System.out.println("");
     } */
     
    
    System.out.print("Output: [");
    for (int i = 0; i < havana.length; i++)
    {
        System.out.print("[");
        for (int j = 0; j < havana[0].length; j++)
        {
            System.out.print(havana[i][j] + ",");
        }
        System.out.print("],");
    }
    System.out.print("]");
    
}
}
