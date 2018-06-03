import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
class BinaryTree 
{
    static Boolean isEvenPalin(int n)
    {
            Boolean flag = true;
            String str = String.valueOf(n);
            int s = str.length();
            if(str.length() %2 != 0)
                flag = false;
            else
            {
                int i = 0;
                int j = s-1;
                while(i < j)
                {
                    if(str.charAt(i) != str.charAt(j))
                        flag =  false;
                    i++;
                    j--;
                }
            }
            return flag ;
    }
    static int fun(int n)
    {
                   
        HashMap<Integer, Integer> mp = new HashMap<>();
        int rk =0, rv= 0;;
        if(!isEvenPalin(n))
            return 0;
        else
        {
            String str = String.valueOf(n);
           // System.out.println(str);
            for(int i = 0;i < str.length(); i++)
            {
               /// int k = Integer.valueOf(str.charAt(i));
                int k =  str.charAt(i) - '0';
             //   System.out.println("Chat At ### " + str.charAt(i));
                if(!mp.containsKey(k))
                {
                    mp.put(k, 1);
                } 
                else
                {
                    int val = mp.get(k);
                     mp.put(k, val +1);
                }
            }
             for (Map.Entry<Integer,Integer> entry : mp.entrySet()) 
             {
               //   System.out.println("Key = " + entry.getKey() +
               //            ", Value = " + entry.getValue());
                 if(entry.getValue() > rv)
                 {
                     rk = entry.getKey();
                     rv = entry.getValue();
                 }
                 else if(entry.getValue() == rv)
                 {
                     if(rk >= entry.getValue())
                     {
                         rk = entry.getKey();
                         rv = entry.getValue();
                     }
                 }
             }
           
            return rk;
        
        }
    }
    
    public static void main(String args[] ) throws Exception 
    {
        ArrayList<Integer> v = new ArrayList<Integer>();
        int T , N;
        Scanner s = new Scanner(System.in);
        T = s.nextInt();
        for(int i = 0 ; i < 100000000 ; i++)
        {
            if(isEvenPalin(i))
            {
                v.add(i);
            }
        }
        while(T > 0)
        {
            N = s.nextInt(); 
            int res = fun(v.get(N-1));
            System.out.println(res);
            T--;
        }
       
    }                     
}
  