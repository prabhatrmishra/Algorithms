import java.util.*;
class Node 
{
    long data;
    Node left, right;
  
    public Node(long item) 
    {
        data = item;
        left = right = null;
    }
}
  
class BinaryTree 
{
    Node root;
      
    
    long getMin(long x, long y) 
    {
        return (x < y) ? x : y;
    }
  
    long waveOp( Node ptr)
    {
        long sum = 0;
        if(ptr== null)
            return 0;

        else
        {
            sum += ptr.data + waveOp(ptr.left) 
                + waveOp(ptr.right);  
        } 
        ptr.data = sum;
        return sum; 
    }
    long minDistance(Node root)
    {
        if (root == null)
            return 0;
        if (root.left == null || root.right == null)
            return 0;

        return 1 + getMin(minDistance(root.left),
                          minDistance(root.right));
    }
    
   long findTreeSum(Node  root){
        long sum = 0;
        if(root == null )
            return 0;
        else 
            sum += (root.data + findTreeSum(root.left) +
                     findTreeSum(root.right));
        return sum;
}
  
    public static void main(String args[] ) throws Exception 
    {
        Vector nodeArray = new Vector();
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
         Long edg;
        String[] e = name.split(" ");
        long N  = Long.valueOf(e[0]);
        long X = Long.valueOf(e[1]);
         String val = s.nextLine();
        String[] valString = val.split(" ");
        for(int i = 0; i < valString.length; i++)
        {
            Node newNode = new Node(Long.valueOf(valString[i]));
            nodeArray.add(newNode);
            //System.out.println(newNode.data);
        }
        edg = N-1;
        while(edg > 0) 
        {
            String eg = s.nextLine();
            String[] edge = eg.split(" "); 
            long u = Long.valueOf(edge[0]);
            long v = Long.valueOf(edge[1]);
            
            if(v == (2 * u))
            nodeArray[u-1].left = nodeArray[v-1];   
            else if( u == (2 * v))
            nodeArray[v-1].left = nodeArray[u-1];
            else if(v == (2 * u + 1))
            nodeArray[u-1].right = nodeArray[v-1];
            else if(u == (2 * v + 1))
            nodeArray[v-1].right = nodeArray[u-1];
            edg--;
        }
    }                     
}
  