//Problem: https://www.hackerrank.com/challenges/sum-vs-xor

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long count = 0;
        //This performs a basic conversion from int to binary using divide by two and checking even or odd
        while(n != 0){
            count += (n%2 == 0)?1:0;
            n/=2; 
        }
        count = (long) Math.pow(2,count);
        System.out.println(count);
    }
}
