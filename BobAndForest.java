import java.util.*;

  
class A 
{
    static int findSum1(int mat[][], int k , int m, int n)
    {
          int res  = 0;
           for (int i=0; i<n-k+1; i++)
           {
              for (int j=0; j<m-k+1; j++)
              {
                  int sum = 0;
                  for (int p=i; p<k+i; p++)
                  {
                    
                     for (int q=j; q<k+j; q++)
                         sum += mat[p][q];
                  }
                  if(sum == (k * k))
                      res +=1;
              }
           }
        return res;
    }    
    
     static int findSum(int[][] mat, int k,int m, int n)
     {
            int res = 0;
            if (k > n || k >m)
            return 0;

            int stripSum[][] = new int[n][m];

           
            for (int j = 0; j < m; j++) 
            {

                       
                        int sum = 0;
                        for (int i = 0; i < k; i++)
                                sum += mat[i][j];
                        stripSum[0][j] = sum;

                       
                        for (int i = 1; i < n - k + 1; i++)
                        {
                            sum += (mat[i + k - 1][j] - mat[i - 1][j]);
                            stripSum[i][j] = sum;
                        }

              }
                for (int i = 0; i < n - k + 1; i++)
                {
                        int sum = 0;
                        for (int j = 0; j < k; j++)
                            sum += stripSum[i][j];
                        if(sum == (k *k))
                            res++;

                        for (int j = 1; j < m - k + 1; j++) {
                            sum += (stripSum[i][j + k - 1] - stripSum[i][j - 1]);
                          
                            if(sum == (k *k))
                            res++;
                        }
                      
                }
         return res;
     }
    
    static int runRobot(int[][] mat, int k, int m, int n)
    {
        int res = 0;
        for(int i = 1; i <= k ; i++)
        {
            int r= findSum(mat, i, m, n);
          //  System.out.println("total no :  " + r);
            res += r;
        }
        return res;
    }
  
    public static void main(String args[] ) throws Exception 
    {
        int N , M, Q , K;
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
        String[] e = name.split(" ");
         N  = Integer.valueOf(e[0]);
         M = Integer.valueOf(e[1]);
        int[][] mat = new int[N][M];
        for(int i = 0 ;i < N ; i++)
        {
            String str = s.nextLine();
            for(int j = 0; j < M ; j++)
            {
                if(str.charAt(j) == '*')
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        
       /* for (int i = 0; i < N; i++)
        { 
            for (int j = 0; j < M; j++)
            { 
                System.out.println(mat[i][j]) ;
            } 
        } */
        
         Q = s.nextInt();
        while(Q >0)
        {
            K = s.nextInt();
           System.out.println(runRobot(mat, K, M, N));
            Q--;
        }
        return ;
    }                     
}
  