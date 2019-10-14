public class Stack {
	private int elem[];
	private int top;

	void initStack(int size) {
		elem = new int[size];
		top = -1;
	}
	void initStack(int [] a) {
		elem = new int[a.length];
		top = -1;
		for(int e: a)
			push(e);

	}
	void initStack(Stack s1) {
		elem = new int[s1.elem.length];
		top = s1.top;
		for(int i=0;i<=top;i++) {
			elem[i]=s1.elem[i];
		}
	}
	
	void push(int e) {
		if(!isFull()) {
			top++;
			elem[top] = e;
		}
		else
			System.out.print("Stack Overflow\n");
	
	}
	
	int pop() {
		if(!isEmpty())
			return (elem[top--]);
	else {
		System.out.print("Stack underflow\n");
		return(-1);
	}
}
	
	void peek() {
		if(top==-1)
			System.out.print("Stack underflow");
		else
			System.out.print("Stack top is :"+ elem[top]+"\n");
	}
	
	void display() {
		System.out.print("\nStack contents are: ");
		for(int i=0;i<=top;i++)
			System.out.print(elem[i]+ " ");
		System.out.print("\n");
	}
	
	boolean isEmpty() {
		return top==-1;
	}
	
	boolean isFull() {
		return top==elem.length-1;
	}
}
public class T5 {

	public static void main(String[] args) {
		int [] a = new int [] {1,2,3,4,5};
		Stack s1 = new Stack();
		Stack s2 = new Stack();
		Stack s3 = new Stack();
		s1.initStack(5);
		s1.display();
		s2.initStack(a);
		s2.display();
		s2.peek();
		s3.initStack(s2);
		s3.display();
		s3.peek();
			System.out.print("Stack top in s3 is : "+s3.pop());
		s3.display();
		s3.peek();
		
	}

}
