import java.util.*;
class Node 
{
    int data;
    Node left, right;
    Node(int x) 
    {
        data = x;
        left = null;
        right = null;
    }
    public static int compareNodes(Node a, Node b) 
    {
        if (a.data < b.data)
            return -1;
        else
            return 1;
    }
}
class Solution 
{
    public void preOrder(Node root, ArrayList<String> ans, String curr) 
    {
        if (root == null)
            return;
        if (root.left == null && root.right == null) 
        {
            ans.add(curr);
            return;
        }
        preOrder(root.left, ans, curr + '0');
        preOrder(root.right, ans, curr + '1');
    }
    public ArrayList<String> huffmanCodes(String S, int f[], int N)
    {
        // code here
        PriorityQueue<Node> pq = new PriorityQueue<>(Node::compareNodes);
        for (int i = 0; i < N; i++) 
        {
            Node tmp = new Node(f[i]);
            pq.add(tmp);
        }
        // build Huffman tree
        while (pq.size() > 1) 
        {
            Node left = pq.poll();
            Node right = pq.poll();
            Node parent = new Node(left.data + right.data);
            parent.left = left;
            parent.right = right;
            pq.add(parent);
        }
        ArrayList<String> ans = new ArrayList<>();
        preOrder(pq.peek(), ans, "");
        return ans;
    }
}
