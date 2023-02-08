import java.util.Scanner;
class Student{
    int r_no;
    Scanner sc = new Scanner(System.in);
    void get_no(){
        System.out.println("Roll no.: "+r_no);
    }
    void put_no(){
        
        System.out.print("Enter roll no.: ");
        r_no=sc.nextInt();
    }
}
class Test extends Student{
    int m1;
    int m2;
    void put_marks()
    {
        System.out.print("Enter marks 1: ");
        m1=sc.nextInt();
        System.out.print("Enter marks 2: ");
        m2=sc.nextInt();
    }
    void get_marks()
    {
        System.out.println("Marks 1: "+m1+" and marks 2: "+m2);
    }
}

interface Sports{
    int sprt_wt=60;
    public void put_wt();
}

class Result extends Test implements Sports
{
    int total;
    int wt;
    public void put_wt(){
        System.out.print("Enter weight of student: ");
        wt=sc.nextInt();
        total = (m1 + m2 + ((wt*100)/sprt_wt))/3;
    }
    void display()
    {
        System.out.println("The result is: "+total);
    }
}

class Family extends Student
{
    String mother;
    String father;
    void put_parents()
    {
        System.out.print("Enter the name of the mother: ");
        mother = sc.next();
        System.out.print("Enter the name of the father: ");
        father = sc.next();
    }
    void get_parents()
    {
        System.out.println("Mother: "+mother+" Father: "+father);
    }
}
class java{
    public static void main(String[] args) {
        Result r1 = new Result();
        r1.put_no();
        r1.put_marks();
        r1.put_wt();
        r1.get_no();
        r1.get_marks();
        r1.display();
        Family f = new Family();
        f.put_parents();
        f.get_parents();
    }
}