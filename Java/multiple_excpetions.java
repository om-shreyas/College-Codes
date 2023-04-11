import java.util.*;
import java.lang.*;

class multile_exceptions {
public static void sus(int a) throws ArithmeticException, NullPointerException {
if(a == 0) {
throw new ArithmeticException("a cannot be zero");
} else if(a == 1) {
throw new NullPointerException("a cannot be one");
} else {
System.out.println(a);
}
}

public static void main(String args[]) {
    int a;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the value of a: ");
    a = sc.nextInt();

    try {
        sus(a);
    } catch(ArithmeticException e) {
        System.out.println(e);
    } catch(NullPointerException e) {
        System.out.println(e);
    } catch(Exception e) {
        System.out.println(e);
    }

    sc.close();
}

}