// Implemening Static and Dynamic Stack
// Author: Ravi Prakash (https://github.com/ravi-prakash1907)

/*
    The file name has not the actual username as my github username include a special charector i.e. ' - '
    The real Username is embedded in this program as a comment (above).
*/


import java.lang.*;
import java.util.ArrayList;
import java.util.Scanner;

abstract class Stack {
  public int index;

  Stack(){}

  public abstract void Push(int x);
  public abstract int Pop();
}

class staticStack extends Stack {
  int arr[];
  staticStack(){
      arr = new int[10];
      this.index = -1;
  }

  public void Push(int x){
    if (index == 9) {
      System.out.println("\nStack Overflow!");
    }
    else{
      this.arr[++index] = x;
      System.out.println("\nPushed successfully!");
    }
  }

  public int Pop(){
    int temp = -1;
    if (index > -1) {
      temp = this.arr[index--];
    }
    else{
      System.out.println("\nStack Underflow!");
    }
    return temp;
  }

  public void Display(){
    if (index > -1) {
      System.out.println("\nStack:\n\n");
      for (int i = index; i >= 0; i--) {
        System.out.println(arr[i] + "  \n");
      }
    }
    else{
      System.out.println("\nStack Underflow!");
    }
  }
}

class dyanamicStack extends Stack {
  ArrayList<Integer> arr;

  dyanamicStack(){
      arr = new ArrayList<Integer>();
      this.index = -1;
  }

  public void Push(int x){
    index++;
    arr.add(x);
    System.out.println("\nPushed successfully!");
  }

  public int Pop(){
    int temp = -1;
    if (index > -1) {
      temp = arr.get(index);
      arr.remove(index--);
    }
    else{
      System.out.println("\nStack Underflow!");
    }
    return temp;
  }

  public void Display(){
      if (index > -1) {
        System.out.println("\nStack:\n\n");
        for (int i = index; i >= 0; i--)
          System.out.println(arr.get(i) + "  \n");
      }
      else{
        System.out.println("\nStack Underflow!");
      }
    }

}

public  class stack_raviprakash1907 {
  public static void main(String[] args) {

    int chooseStack, choice = -1, data;
    Scanner s = new Scanner(System.in);

    do {
         System.out.println("\nImplement a:\n" +
                            "\n1) Static Stack (size = 10)" +
                            "\n2) Dyanamic Stack" +
                            "\n\n*  Somthing else, to EXIT" +
                            "\n  ____________________\n");
        chooseStack = s.nextInt();


        switch (chooseStack) {
          case 1: staticStack sStack;
                  sStack = new staticStack();
                  do {
                       System.out.println("\nMenu:\n" +
                                          "\n  _______\n" +
                                          "\n1) Push" +
                                          "\n2) Pop" +
                                          "\n3) Display" +
                                          "\n ____________________\n");
                      choice = s.nextInt();

                      switch (choice) {
                        case 1: System.out.println("\nEnter data to push: ");
                                data = s.nextInt();
                                sStack.Push(data);
                                break;

                        case 2: data = sStack.Pop();
                                System.out.println("\nPopped: " + data);
                                break;

                        case 3: sStack.Display();
                                break;

                        default: break;
                      }
                  } while (choice <= 3 && choice >= 1);
                  break;

          case 2: dyanamicStack dStack;
                  dStack = new dyanamicStack();
                  do {
                       System.out.println("\nMenu:\n" +
                                          "\n  _______\n" +
                                          "\n1) Push" +
                                          "\n2) Pop" +
                                          "\n3) Display" +
                                          "\n ____________________\n");
                      choice = s.nextInt();

                      switch (choice) {
                        case 1: System.out.println("\nEnter data to push: ");
                                data = s.nextInt();
                                dStack.Push(data);
                                break;

                        case 2: data = dStack.Pop();
                                System.out.println("\nPopped: " + data);
                                break;

                        case 3: dStack.Display();
                                break;

                        default: break;
                      }
                  } while (choice <= 3 && choice >= 1);
                  break;

          default: break;
        }
    } while (choice == 1 && choice == 2);

  }
}
