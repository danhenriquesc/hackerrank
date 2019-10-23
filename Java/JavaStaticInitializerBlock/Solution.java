import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

public static int B;
public static int H;
public static boolean flag;
private static final Scanner scanner = new Scanner(System.in);

static {
    B = scanner.nextInt();
    H = scanner.nextInt();
    if (B <= 0 || H <= 0){
        System.out.println("java.lang.Exception: Breadth and height must be positive");
    } else {
        flag = true;
    }
}

public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
		
	}//end of main

}//end of class

