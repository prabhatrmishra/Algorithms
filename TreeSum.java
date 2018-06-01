import java.util.*;
class Node 
{
    int data;
    Node left, right;
  
    public Node(int item) 
    {
        data = item;
        left = right = null;
    }
}
  
class BinaryTree 
{
    Node root;
      
    
    int getMin(int x, int y) 
    {
        return (x < y) ? x : y;
    }
  
    int waveOp( Node ptr)
    {
        int sum = 0;
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
    int minDistance(Node root)
    {
        if (root == null)
            return 0;
        if (root.left == null || root.right == null)
            return 0;

        return 1 + getMin(minDistance(root.left),
                          minDistance(root.right));
    }
    
   int findTreeSum(Node  root){
        int sum = 0;
        if(root == null )
            return 0;
        else 
            sum += (root.data + findTreeSum(root.left) +
                     findTreeSum(root.right));
        return sum;
}
  
    public static void main(String args[] ) throws Exception 
    {
         BinaryTree tree = new BinaryTree();
        ArrayList<Node> nodeArray = new ArrayList<Node>();
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
         int edg;
        String[] e = name.split(" ");
        int N  = Integer.valueOf(e[0]);
        int X = Integer.valueOf(e[1]);
         String val = s.nextLine();
        String[] valString = val.split(" ");
        for(int i = 0; i < valString.length; i++)
        {
            Node newNode = new Node(Integer.valueOf(valString[i]));
            nodeArray.add(newNode);
            //System.out.println(newNode.data);
        }
        edg = N-1;
        while(edg > 0) 
        {
            String eg = s.nextLine();
            String[] edge = eg.split(" "); 
            int u = Integer.valueOf(edge[0]);
            int v = Integer.valueOf(edge[1]);
            
            if(v == (2 * u))
            {
             Node node =nodeArray.get(u-1);
                node.left = nodeArray.get(v-1);   
            }
            
            else if( u == (2 * v))
           nodeArray.get(v-1).left = nodeArray.get(u-1);
            else if(v == (2 * u + 1))
            nodeArray.get(u-1).right = nodeArray.get(v-1);
            else if(u == (2 * v + 1))
            nodeArray.get(v-1).right = nodeArray.get(u-1);
            edg--;
        }
         tree.waveOp(nodeArray.get(0)); 
    
        int dist = tree.minDistance(nodeArray.get(0));
 
        int sum = tree.findTreeSum(nodeArray.get(0));
        int treeSum = sum + ((dist +  2)* X);
        System.out.println(treeSum);
    }                     
}
  