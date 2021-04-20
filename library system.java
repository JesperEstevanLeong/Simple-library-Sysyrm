
package test.pkg3;

import java.util.ArrayList;
import java.util.Scanner;
public class Test3 {

    public static void main(String[] args) {
        ArrayList<String> Books = new ArrayList<>();
        Scanner H = new Scanner (System.in);
        int num = 0;
        System.out.println(">>>>>>>>>>>>>>>>>>>>>>");
        System.out.println(">Welcom to The System>");
        System.out.println(">>>>>>>>>>>>>>>>>>>>>>");
        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>");
        System.out.println(">Hi,what is your name?>");
        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>");
        String name = H.nextLine();
        while (num != 4){
        System.out.println(">>>>>>>>>>>");    
        System.out.println(">Main Menu>");
        System.out.println(">>>>>>>>>>>");
        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        System.out.println(">Select the fuction from 1 to 4>");
        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        System.out.println("1. Insert Book List");
        System.out.println("2. View Book List");
        System.out.println("3. Update Book List");
        System.out.println("4. Exit Program");
        try{
        num = H.nextInt();
        }catch (Exception e){
            System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
            System.out.println(">Please select a valid option>");
            System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        }
        H.nextLine();
        switch (num) {
            case 1:
                int num2 = 0;
                while (num2 != 1 && num2 != 2 && num2 != 3){
                System.out.println(">>>>>>>>>>>>>>>>");
                System.out.println("Insert Book List");
                System.out.println(">>>>>>>>>>>>>>>>");
                System.out.println("1. One book");
                System.out.println("2. Five books");
                System.out.println("3. Custom");
                try{
                num2 = H.nextInt();
                }catch (Exception e){
                System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                System.out.println(">Please select a valid option>");
                System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                }
                H.nextLine();
                switch (num2) {
                    case 1:  
                      System.out.println(">>>>>>>>>>>>>>>>>");
                      System.out.println(">Enter Book name>");
                      System.out.println(">>>>>>>>>>>>>>>>>");
                      for (int i = 0; i < 1; i++){
                      String x = H.nextLine();
                      Books.add(x);
                      }
                      System.out.println(Books);
                     
                    break;
                    case 2:
                      System.out.println(">>>>>>>>>>>>>>>>>>");
                      System.out.println(">Enter Book names>");
                      System.out.println(">>>>>>>>>>>>>>>>>>");
                      for (int i = 0; i < 5; i++){
                      String x = H.nextLine();
                      Books.add(x);
                      }
                      System.out.println(Books);
                    break;
                    case 3:
                      System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>");
                      System.out.println(">Please insert a number>");
                      System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>");
                      int number = H.nextInt();
                      H.nextLine();
                      System.out.println(">>>>>>>>>>>>>>>>>>");
                      System.out.println(">Enter Book names>");
                      System.out.println(">>>>>>>>>>>>>>>>>>");
                      for (int i = 0; i < number; i++){
                      String x = H.nextLine();
                      Books.add(x);
                      }
                      System.out.println(Books);
                    break;
                    default: 
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        System.out.println(">Please insert a valid number>");
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                    break;
                    
                  }
                }
                break;
                
                
            case 2:
                int numsorted = 0;
                String temp1 = "";
                String temp2 = "";  
                String[] temp = new String[Books.size()];
                for(int i = 0; i < Books.size(); i++) {
                temp[i] = Books.get(i);
                }
                System.out.println(">>>>>>>>>>>>>>>>");
                System.out.println(">View Book List>");
                System.out.println(">>>>>>>>>>>>>>>>");
                System.out.println(">>>>>>>>>>>>>>>>>>>>>");
                System.out.println(">Please enter 1 or 2>");
                System.out.println(">>>>>>>>>>>>>>>>>>>>>");
                System.out.println("1.Ascending order");
                System.out.println("2.Descending order");
                int num3 = H.nextInt();
                switch (num3) {
                    case 1:
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        System.out.println(">Book List show in ascending order>");
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        while(numsorted < Books.size()){
                        for (int index=1; index < (Books.size() - numsorted);index++)
                        {
                        if(temp[index-1].compareToIgnoreCase(temp[index])>0){
                        temp1 = temp [index-1];
                        temp[index-1] = temp[index];
                        temp[index]=temp1;
                      }
                   }
                   numsorted++;
                 }
                        for (int i = 0; i < temp.length; i++){
            	        System.out.print(temp[i]+"\t");
                        }
                        System.out.println();
                        break;
                        
                    case 2:
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        System.out.println(">Book List show in descending order>");
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        for (int i= 0; i < Books.size(); i++) {
                        int max = i;
                        for (int k = i + 1; k < Books.size(); k++) {
                        if (temp[k].compareToIgnoreCase(temp[max]) > 0) 
                        {
                        max = k;
                        }
                    }
                       temp2 = temp [i];
                       temp[i] = temp[max];
                       temp[max] = temp2;
                        }
                        for (int i = 0; i < temp.length; i++){
            	        System.out.print(temp[i]+"\t");
                        }
                        
                        System.out.println();
                        break;
                        
                        
                    default:
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        System.out.println(">Please insert a valid number>");
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        break ;   
                }
                break;
        
                    case 3:
              
                        System.out.println(">>>>>>>>>>>>>>>>>>");
                        System.out.println(">Update Book List>");
                        System.out.println(">>>>>>>>>>>>>>>>>>");
                        System.out.println("1.remove Book List");
                        int num4 = H.nextInt();
                
                switch (num4){
                    case 1:
                        H.nextLine();
                        String Z= "";
                        int change1 = 0;
                        System.out.println(">>>>>>>>>>>>>>>>>>");
                        System.out.println(">remove Book List>");
                        System.out.println(">>>>>>>>>>>>>>>>>>");
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        System.out.println(">What is the book name you want to remove>");
                        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                        Z = H.nextLine();
                        for (int i = 0; i < Books.size(); i++){
                        if (Z.equalsIgnoreCase(Books.get(i))){
                        
                            change1 = i;
                        }
                        }
                        
                        Books.remove(change1);
                        break;
                            
                }
                break;
            case 4:
                System.out.println("Exit Program");
                break;
            default:
                break;
        }
    }
}    
}
    

    

