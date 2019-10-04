//A java program to calculate day Number by giving a date as input

import java.io.*;
class Date_to_Day
{
      public static void main(String args[])throws IOException
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            System.out.println("Enter Date in DD/MM/YYYY format");
            String date=br.readLine();//Accepting Input
            
            int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};//Storing days of month in array
            
            int s=Integer.parseInt(date.substring(0,(date.indexOf('/'))));//Separating the date
            
            int x1=date.indexOf('/');//Finding the Starting index for month 
            
            int y1=date.lastIndexOf('/');//Extracting Month from Complete Date
            
            String x=date.substring(x1,y1);
            
            char y=(x.charAt(x.length()-1));
            
            int mn=Integer.parseInt(String.valueOf(y));
            
            for(int i=1;i<mn;i++)//Loop to calculate day number
            {
                s+=days[i];
            }
            
            System.out.println("Day Number:"+s);//Output Display
    }

}        
    
