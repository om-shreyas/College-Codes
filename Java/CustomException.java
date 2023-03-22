import java.lang.*;
public class CustomException {
    public static void main(String[] args) {
        int a=10;
        int b=1;
        int c=10;
        try{
            int d = b*b-4*a*c;
            if(d<0)
            {
                throw new ArithmeticException("This is a custom exception");
            }
        }
        catch(ArithmeticException e){
            System.out.println(e);
        }
    }
}
