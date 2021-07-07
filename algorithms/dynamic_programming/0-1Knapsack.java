//Consider a thief gets into a home to rob and he carries a knapsack. 
//There are fixed number of items in the home each with its own weight and value Jewellery, with less weight and highest value vs tables, with less value but a lot heavy. 
//To add fuel to the fire, the thief has an old knapsack which has limited capacity.
//Obviously, he cant split the table into half or jewellery into 3by4. 
//He either takes it or leaves it

/*
    Knapsack Max weight       :       W = 10 (units)

    Total items              :       N = 4

    Values of items          :       v[] = {10, 40, 30, 50}

    Weight of items          :       w[] = {5, 4, 6, 3}

*/

import java.io.*;

class knapsack {
    
    //1. Naive Recursive approach
    public static int ksR(int W, int[] wt,int[] val,int n)
    {
        //to store max value of subset of val[]
        int sack=0;
        
        //Base case
        if(n<=0)
        {
            return 0;
        }
        
        //Case1. we add a value corresponding weight only if the corresponding weight is less than the total weight given
        // as total weight available is being updated every time 
        //we check wt[n-1] only and not sum of weights
        if(wt[n-1]<=W)
        {
        sack=Math.max((val[n-1]+ksR(W-wt[n-1],wt,val,n-1)),ksR(W,wt,val,n-1));
        }
        
        //Case2. else dont add value for that corresponding weight
        else{
        sack=ksR(W,wt,val,n-1);
        } 
    
    return sack;
    }
    
    public static int ksTD(int W,int[] wt,int[] val,int n,int[] temp)
    {
        //to store max value after summing the values of subset of val[]
        int sack=0;
        
        //Base case
        if(n<=0)
        {
            return 0;
        }
        
        //If subprob already solved 
        if(temp[n-1]>0)
        {
            return temp[n-1];
        }
        
        // we add a value correspoding weight only if the corresponding weight is less than the total weight given
        if(wt[n-1]<=W)
        {
        sack=Math.max((val[n-1]+ksR(W-wt[n-1],wt,val,n-1)),ksR(W,wt,val,n-1));
        }
        
        //else dont add value for that corresponding weight
        else{
        sack=ksR(W,wt,val,n-1);
        } 
        
        //if new subprob is solved store the result
        temp[n-1]=sack;
        
        return sack;
    }
    
    public static int ksBU(int W,int[] wt,int[] val,int n,int[][] temp)
    {
        //Analogous to base case in recursion
        for (int i=0;i<=n;i++)
        {
            temp[i][0]=0;
        }
        
        for(int i=0;i<=W;i++)
        {
            temp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                temp[i][j]=temp[i-1][j];
                
                if(wt[i-1]<=W)
                {
                    temp[i][j]=Math.max(val[i-1]+temp[i-1][W-wt[i-1]],temp[i-1][j]);
                }
            }
        }
        return temp[n-1][W];
    }
	public static void main (String[] args) {
		System.out.println("GfG!");
		int val[] = new int[]{60, 100, 120}; 
        int wt[] = new int[]{10, 20, 30}; 
    int  W = 50; 
    int n = val.length; 
    
    int temp[]=new int[n];
    
    int temp2[][]=new int[n+1][W+1];
    
    
    
    for(int i=0;i<n;i++)
    {
        temp[i]=0;
    }
    System.out.println(ksR(W, wt, val, n)); 
    System.out.println(ksTD(W, wt, val, n,temp)); 
    System.out.println(ksBU(W, wt, val, n,temp2)); 

	    
	}
	
}