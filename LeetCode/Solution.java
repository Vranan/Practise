import java.util.*;
public class Solution {
    private int jew = 0;
   
    public int numJewelsInStones(String J, String S) {
        Map<Character, String> stone = new HashMap<Character, String>();
        
        for (int k = 0; k < J.length(); k++) {
            stone.put(J.charAt(k), "J");
        }
        
        for (int i = 0; i < S.length(); i++) {
            if (stone.get(S.charAt(i)) == "J") {
                jew++;
            }
            else 
                continue;
        }
        return jew;
    }
    
    public static void main(String[] args) {
        Solution js = new Solution();
        System.out.println("Output: " + js.numJewelsInStones("aA","aAAbbbb"));
    }
}
    