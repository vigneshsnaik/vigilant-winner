import java.io.*;
public class palindrome{
    public static void main(String a[]){
        int i,n=161,digit,rev=0,nCpy=n;
        while(n!=0){
            digit=n%10;
            rev=rev*10+digit;
            n=n/10;
        }
        if (nCpy!=rev){
            System.out.print("Not ");
        }
        System.out.println("Palindrome");
    }
}