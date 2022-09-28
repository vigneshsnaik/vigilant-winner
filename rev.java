import java.io.*;
public class rev{
    public static void main(String a[]){
        int i,n=165,digit,rev=0;
        while(n!=0){
            digit=n%10;
            rev=rev*10+digit;
            n=n/10;
        }
        
        System.out.println("Reverse="+rev);
    }
}