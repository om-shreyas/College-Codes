import java.util.*;

class QuadraticEquationSolver {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int coefficientA = input.nextInt();
        int coefficientB = input.nextInt();
        int coefficientC = input.nextInt();

        double discriminantSquare = (coefficientB * coefficientB) - (4 * coefficientA * coefficientC);

        try {
            if (discriminantSquare < 0) {
                throw new ArithmeticException("Equation gives imaginary roots!");
            }
        } catch (ArithmeticException exception) {
            System.out.println(discriminantSquare);
        }
        input.close();
    }
}
