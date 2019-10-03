import java.math.BigDecimal;
import java.util.*;
class Solution{

    public static void main(String []args){
        //Input
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String []s=new String[n+2];
        for(int i=0;i<n;i++){
            s[i]=sc.next();
        }
      	sc.close();

        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                BigDecimal jD = new BigDecimal(s[j]);
                BigDecimal jD1 = new BigDecimal(s[j+1]);
                if (jD.compareTo(jD1) < 0){
                    String jString = s[j];
                    String jString1 = s[j + 1];
                    s[j+1] = jString;
                    s[j] = jString1;
                }
            }
        }


        //Output
        for(int i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }
    }

}
