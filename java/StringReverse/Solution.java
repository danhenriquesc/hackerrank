import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        
        String yes = "Yes";
        String no = "No";

        int limit = A.length() % 2 != 0 ? A.length() / 2 : (A.length() / 2) - 1;
        for (int i = 0; i < limit; i++){
            if (A.charAt(i) != A.charAt(A.length() - 1 - i)){
                System.out.println(no);
                return;
            }
        }
        System.out.print(yes);
    }
}
