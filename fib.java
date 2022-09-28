import java.io.*;
public class fib{
    public static void main(String arg[]){
        int t1 = 0, t2 = 1;
        int nextTerm = t1 + t2;
        int i,n=30;
        System.out.println("Enter the number of terms: ");

        System.out.println("Fibonacci Series: ");
        System.out.println(t1);
        System.out.println(t2);

        for (i = 3; i <= n; ++i) {
            System.out.println(nextTerm);
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        }

    }
}