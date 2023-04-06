import java.util.Scanner;

class Student{
    Scanner sc = new Scanner(System.in);
    int rn;
    int sub1;
    int sub2;
    int sub3;
    int total;
    static int m1,m2,m3,m4;
    static int r1,r2,r3,r4;
    Student()
    {
        rn=0;
        sub1=0;
        sub2=0;
        sub3=0;
        total=0;
        
    }
    void get()
    {
        System.out.println("Enter roll: no.: ");
        rn = sc.nextInt();
        System.out.println("Enter marks 1 : ");
        sub1 = sc.nextInt();
        System.out.println("Enter marks 2 : ");
        sub2 = sc.nextInt();
        System.out.println("Enter marks 3 : ");
        sub3 = sc.nextInt();
    	if(sub1>m1)
        {
            m1 = sub1;
            r1 = rn;
        }
        if(sub2>m2)
        {
            m2 = sub2;
            r2 = rn;
        }
        if(sub3>m3)
        {
            m3 = sub3;
            r1 = rn;
        }
        total = sub1+sub2+sub3;
        if(total>m4)
        {
            m4 = total;
            r1 = rn;
        }
    }
    void print()
    {
        System.out.println("Test");
    }
}

public class Exam
{
	public static void main(String[] args) {
	    System.out.println("Test");
	    Student[] s = new Student[10];
        System.out.println("Test");
	    for(int i=0;i<10;i++)
	    {
            s[i] = new Student();
            s[i].get();
	    }
        System.out.println("Student "+s[1].m1+" "+s[1].r1);
        System.out.println("Student "+s[1].m2+" "+s[1].r2);
        System.out.println("Student "+s[1].m3+" "+s[1].r3);
        System.out.println("Student "+s[1].m4+" "+s[1].r4);
	}
}
