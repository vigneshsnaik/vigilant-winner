import java.io.*;
public class armstrong{
    public static void main(String a[]){
        int i,n=163,digit,sumcub=0,nCpy=n;
        while(n!=0){
            digit=n%10;
            sumcub+=(digit*digit*digit);
            n=n/10;
        }
        if (nCpy!=sumcub){
            System.out.print("Not ");
        }
        System.out.println("Armstrong");
    }
}