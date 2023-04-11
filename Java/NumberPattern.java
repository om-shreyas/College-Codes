import java.util.*;

class NumberPattern {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int numberCount = 1;
        System.out.print("Enter number of lines: ");
        int lineCount = input.nextInt();
        for (int i = 1; i <= lineCount; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(numberCount++ + " ");
            }
            System.out.println();
        }
        input.close();
    }
}
