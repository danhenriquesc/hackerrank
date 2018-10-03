import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class SockMerchantSolution {
    
    static int sockMerchant(int n, int[] ar) {
        Map<Integer, Integer> colorCounter = new HashMap<Integer, Integer>();
        for(int index=0;index<n;index++){
            int k = ar[index];
            if(!colorCounter.containsKey(k)) 
                colorCounter.put(k,1);
            else 
                colorCounter.replace(k,colorCounter.get(k)+1);
        }
        Collection pairsCounter = colorCounter.values();
        int pairsForSale = 0;
        Iterator it = pairsCounter.iterator();
        while(it.hasNext()){
            int numberOfSocks = (int)(it.next());
            
            if(numberOfSocks%2==0) {
                pairsForSale+=(int)(numberOfSocks/2);
            }
                
            if(numberOfSocks%2!=0) {
                pairsForSale+=(int)((numberOfSocks-1)/2);
            }
        }
        return pairsForSale;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}