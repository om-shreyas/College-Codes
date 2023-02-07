import java.util.Scanner;
import java.util.Arrays;

class sort_string{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char arr[] = s.toCharArray();
        Arrays.sort(arr);
        System.out.println(arr);
        sc.close();
    }
}