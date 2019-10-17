package AVLTrees;

public class AVLSearchTree {
	private class Node
	{
		int data;
		int height;
		Node left;
		Node right;
	
		Node(int data)
		{
			this.data = data;
			this.height = 1;
			this.left = null;
			this.right = null;
		}
	}
	
	private Node root;
	private int size;
	
	AVLSearchTree()
	{
		this.root = null;
		this.size = 0;
	}
	
	public int size()
	{
		return this.size;
	}
	
	public int height()
	{
		return this.root.height;
	}
	
	public void insert(int data)
	{
		if(this.root==null)
		{
			Node node = new Node(data);
			this.root = node;
			return;
		}
		this.root = insertFunc(this.root,data);
	}
	
	private Node insertFunc(Node node,int data)
	{
		/* 1.  Perform the normal BST insertion */
        if (node == null)
            return (new Node(data));
        if (data < node.data)
            node.left = insertFunc(node.left, data);
        else if (data > node.data)
            node.right = insertFunc(node.right, data);
        else // Duplicate keys not allowed
            return node;
		
        /* 2. Update height of this ancestor node */
        setHeight(node);
		
        /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
        int bf = bf(node);
        // Left Left Case
        if (bf > 1 && data < node.left.data)
            return RightRotate(node);
        // Left Right Case
        if (bf > 1 && data > node.left.data)
        {
            node.left = LeftRotate(node.left);
            return RightRotate(node);
        }
        // Right Right Case
        if (bf < -1 && data > node.right.data)
            return LeftRotate(node);
        // Right Left Case
        if (bf < -1 && data < node.right.data)
        {
            node.right = RightRotate(node.right);
            return LeftRotate(node);
        }
        /* return the (unchanged) node pointer */
        return node;
	}
	
	private void setHeight(Node node)
	{
		int hl=0,hr=0;
		if(node.left!=null)
			hl = node.left.height;
		if(node.right!=null)
			hr = node.right.height;
		node.height = Math.max(hl,hr)+1;
	}
	
	private int bf(Node node)
	{
		int hl=0,hr=0;
		if(node.left!=null)
			hl = node.left.height;
		if(node.right!=null)
			hr = node.right.height;
		return hl - hr;
	}
	
	private Node LeftRotate(Node x)
	{
		Node y = x.right;
		Node c = y.left;
		y.left = x;
		x.right = c;
		this.setHeight(x);
		this.setHeight(y);
		return y;
	}
	
	private Node RightRotate(Node x)
	{
		Node y = x.left;
		Node c = y.right;
		y.right = x;
		x.left = c;
		this.setHeight(x);
		this.setHeight(y);
		return y;
	}
	
	public void display()
	{
		displayFunc(this.root);
	}
	
	private void displayFunc(Node node)
	{
		if(node.left!=null)
			System.out.print(node.left.data+"=>");
		else
			System.out.print("NULL=>");
		System.out.print(node.data);
		if(node.right!=null)
			System.out.print("<="+node.right.data);
		else
			System.out.print("<=NULL");
		System.out.print("\n");
		if(node.left!=null)
			displayFunc(node.left);
		if(node.right!=null)
			displayFunc(node.right);
	}
	
	public void delete(int data)
	{
		if(this.root==null)
		{
			System.out.println("Underflow Condititon");
			return;
		}
		this.root = deleteFunc(this.root,data);
	}
	
	private Node deleteFunc(Node node,int data)
	{
		/* 1.  Perform the normal BST deletion */
		if(node==null)
		{
			System.out.println("Data does not exist");
			return null;
		}
		if(data<node.data)
			node.left = deleteFunc(node.left, data);
		else if(data>node.data)
			node.right = deleteFunc(node.right, data);
		else
		{
			if(node.left==null && node.right==null)
				return null;
			else if(node.left==null)
				return node.right;
			else if(node.right==null)
				return node.left;
			else
			{
				int val = MinValFunc(node.right);
				node.data = val;
				node.right = deleteFunc(node.right, val);
			}
		}
		
		/* 2. Update height of this ancestor node */
        setHeight(node);
		
        /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
		
		int bf = bf(node);
		int bfl=0,bfr=0;
		if(node.left!=null)
			bfl = bf(node.left);
		if(node.right!=null)
			bfr = bf(node.right);
        // Left Left Case
        if (bf > 1 && bfl >= 0)
            return RightRotate(node);
        // Left Right Case
        if (bf > 1 && bfl < 0)
        {
            node.left = LeftRotate(node.left);
            return RightRotate(node);
        }
        // Right Right Case
        if (bf < -1 && bfr <= 0)
            return LeftRotate(node);
        // Right Left Case
        if (bf < -1 && bfr > 0)
        {
            node.right = RightRotate(node.right);
            return LeftRotate(node);
        }
        return node;
	}
	
	private int MinValFunc(Node node)
	{
		if(node.left==null)
			return node.data;
		return MinValFunc(node.left);
	}
}
