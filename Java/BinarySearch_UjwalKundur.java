import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class BinarySearch_UjwalKundur{

    public static void bin_search(ArrayList<Integer> n, int s){

        int low = 0;						// initializing left index
        int high = n.size()-1;				// initializing right index

        while(low <= high){

        	int index = (low+high)/2; 		// finding the mid point of the list
        	
            if(n.get(index) < s){ 			// element in upper half, so ignore lower half

            	low = index + 1;			

            }else if(n.get(index) > s){		// element in lower half, so ignore upper half

                high = index - 1;

            }else{
                System.out.println(s+" Found at index "+index);
                return;
            }

        }

        System.out.println(s+" was not Found in the given List");		// If we reach this part of the code that means the element is not in the list
        return;

    }

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of numbers you want to search");
        int len = in.nextInt();

        System.out.println("Enter the numbers you want to Search");        
        ArrayList<Integer> n = new ArrayList<Integer>();

        for(int i = 0; i < len; i++){

            n.add(in.nextInt());

        }
        
        System.out.println("Enter the number to be Searched");
        int s = in.nextInt();

        Collections.sort(n);  						// Binary Search ONLY WORKS ON SORTED Lists

        bin_search(n, s);

    }

}
