import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static long candies(int n, long[] arr) {
        // Complete this function
        long[] prev=new long[n];
        prev[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1])
                prev[i]=1;
            else
                prev[i]=prev[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]&&(prev[i]<=prev[i+1]))
                prev[i]=prev[i+1]+1;
            
        }
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=prev[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] arr = new long[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
            arr[arr_i] = in.nextLong();
        }
      long result = candies(n, arr);
        System.out.println(result);
        in.close();
    }
}
