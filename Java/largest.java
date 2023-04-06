class number{
    int n;
    number(int num)
    {
        n=num;
    }
    void print_largest(number n1)
    {
        if(n<n1.n)
        {
            System.out.println("The largest number is "+n1.n);
        }
        else if(n==n1.n)
        {
            System.out.println("Both Numbers are equal "+n);
        }
        else
        {
            System.out.println("The largest number is "+n);
        }
    }
}

public class largest {
    public static void main(String[] args) {
        number n1 = new number(5);
        number n2 = new number(4);
        n1.print_largest(n2);
    }
}
