/*Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2. */

import java.io.*;
import java.util.*;

class GFG {
    
    // Naive recursive approach
    //based on pascal triangle
    
    public static int bCoeff(int n,int k)
    {
        //Base case 
        if(k==0||k==n)
        {
            return 1;
        }
            
    return bCoeff(n-1,k-1)+bCoeff(n-1,k);
        
        
    }
    
    // Using DP
    public static int bCoeffBU(int n,int k )
    {
        int coeffs[][]=new int[n+1][k+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=Math.min(i,k);j++)
            {
                //analogous to base case
                if(j==0||j==i)
                {
                    coeffs[i][j]=1;
                }
                //From pascal's triangle
                else
                {
                    coeffs[i][j]=coeffs[i-1][j-1]+coeffs[i-1][j];
                }
                
            }
        }
        return coeffs[n][k];
    }
    
    //Also attempt space optimized solution after dry run
	public static void main (String[] args) {
		System.out.println("GfG!");
		int n = 5, k = 2; 
        System.out.println("Value of  "+bCoeff(n, k)); 
        System.out.println("Value of  "+bCoeffBU(n, k)); 

	}
}