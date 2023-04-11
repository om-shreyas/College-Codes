import java.util.Scanner;

interface AdvancedArithmetic {
    public int sumOfDivisors(int n);
}

class Calculator implements AdvancedArithmetic {
    public int sumOfDivisors(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        return sum;
    }
}

class MyCalculator {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        Calculator calculator = new Calculator();
        int n = input.nextInt();
        System.out.println("Sum of factors of the number: " + calculator.sumOfDivisors(n));
        input.close();
    }
}
