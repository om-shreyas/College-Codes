import java.util.*;

class Compare {
    int x;
    int y;
    
    Compare(int a, int b) {
        x = a;
        y = b;
    }
    
    void compare() {
        if (x > y) {
            System.out.println(x + " is greater.");
        } else {
            System.out.println(y + " is greater.");
        }
    }
}

class TwoNumCompare {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int m = sc.nextInt();
        System.out.print("Enter second number: ");
        int n = sc.nextInt();
        Compare C1 = new Compare(m, n);
        C1.compare();
    }
}
