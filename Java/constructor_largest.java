class number{
    int n;
    number(int num)
    {
        n = num;
    }
    void return_large(number n2)
    {
        if(n>n2.n)
        {
            System.out.println(n);
        }
        else if(n==n2.n)
        {
            System.out.println("THE NUMBERS ARE EQUAL: "+n);
        }
        else
        {
            System.out.println(n2.n);
        }
    }
}
class constructor_largest{
    public static void main (String[] args)
    {
        number n1 = new number(5);
        number n2 = new number(10);
        n2.return_large(n1);
    }
}