import java.util.*;
public class delete_string{
    public static String delete(String str,int m)
    {
        String s2 = "";
        for(int i =0;i<str.length();i++)
        {
            if(i!=m-1)
            {
                s2 = s2 + str.charAt(i);
            }
        }
        return(s2);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the String: ");
        String s = sc.nextLine();
        System.out.println("Enter the index value");
        int m = sc.nextInt();
        System.out.println(delete(s, m));
    }
}