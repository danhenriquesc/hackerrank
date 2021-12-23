import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String prime = scanner.nextLine();
        BigInteger primeInteger = new BigInteger(prime);
        boolean isPrime = primeInteger.isProbablePrime(100);
        System.out.print(isPrime ? "prime": "not prime");
        scanner.close();
    }
}
