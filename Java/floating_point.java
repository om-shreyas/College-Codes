import java.util.Scanner;
import java.lang.Math;
class floating_point{
    public static void main(String[] args) {
        double d1;
        double d2;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number 1: ");
        d1 = sc.nextDouble();
        System.out.print("Enter number 1: ");
        d2 = sc.nextDouble();
        if(Math.abs(d1-d2)<0.001)
        {
            System.out.println("The numbers are equal");
        }
        else
        {
            System.out.println("The numbers are unequal");
        }
        sc.close();
    }
}