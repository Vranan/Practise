import java.util.*;
public class JewelsAndStones {
    private int jew = 0;
    
   /* public JewelsAndStones(String stones, String jewels) {
        S = stones;
        J = jewels;
    }
    */
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
        JewelsAndStones js = new JewelsAndStones();
        System.out.println("number of jewels = " + js.numJewelsInStones("aA","aAAbbbb"));
    }
}
    