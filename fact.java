import java.io.*;
public class fact{
    public static void main(String a[]){
        int i,N=5,fact=1;
        for(i=1;i<=N;i++){
            fact*=i;
        }
        System.out.println(fact);
    }
}