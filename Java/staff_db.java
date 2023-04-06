import java.util.Scanner;
abstract class Staff {
    int code;
    String name;

    Staff(int c, String n) {
        code = c;
        name = n;
    }

    abstract void display();
}

class Teacher extends Staff {
    int ppr_publ;

    Teacher(int c, String n, int pp) {
        super(c, n);
        ppr_publ = pp;
    }

    void display() {
        System.out.println("Teacher "+code + " " + name + " " + ppr_publ);
    }
}

class Typist extends Staff {
    int speed;

    Typist(int c, String n, int s) {
        super(c, n);
        speed = s;
    }

    void display() {
        System.out.println("Typist "+code + " " + name + " " + speed);
    }
}

class Casual extends Typist {
    int daily;

    Casual(int c, String n, int speed, int dw) {
        super(c, n, speed);
        daily = dw;
    }

    void display() {
        System.out.println("Casual Typist "+code + " " + name + " " + speed + " " + daily);
    }
}

class Regular extends Typist {
    int salary;

    Regular(int c, String n, int speed, int sal) {
        super(c, n, speed);
        salary = sal;
    }

    void display() {
        System.out.println("Regular Typist "+code + " " + name + " " + speed + " " + salary);
    }
}

class Officer extends Staff {
    String grade;

    Officer(int c, String n, String g) {
        super(c, n);
        grade = g;
    }

    void display() {
        System.out.println("Officer "+code + " " + name + " " + grade);
    }
}

public class staff_db {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of employees");
        int n = sc.nextInt();
        Staff s[] = new Staff[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter Choice");
            int c = sc.nextInt();
            int code;
            String name;
            int ppr_publ;
            int speed;
            int daily;
            int salary;
            String grade;
            switch(c)
            {
                case 1:
                System.out.println("Enter Code: ");
                code = sc.nextInt();
                System.out.println("Enter Name:");
                name = sc.next();
                System.out.println("Enter the number of publication: ");
                ppr_publ = sc.nextInt();
                s[i]= new Teacher(code, name, ppr_publ);
                break;

                case 2:
                System.out.println("Enter Code: ");
                code = sc.nextInt();
                System.out.println("Enter Name: ");
                name = sc.next();
                System.out.println("Enter type speed: ");
                speed = sc.nextInt();
                System.out.println("Enter daily wage: ");
                daily = sc.nextInt();
                s[i]= new Casual(code, name, speed, daily);
                break;

                case 3:
                System.out.println("Enter Code: ");
                code = sc.nextInt();
                System.out.println("Enter Name: ");
                name = sc.next();
                System.out.println("Enter type speed: ");
                speed = sc.nextInt();
                System.out.println("Enter salary: ");
                salary = sc.nextInt();
                s[i]= new Regular(code, name, speed, salary);
                break;

                case 4:
                System.out.println("Enter Code: ");
                code = sc.nextInt();
                System.out.println("Enter Name: ");
                name = sc.next();
                System.out.println("Enter the grade: ");
                grade = sc.next();
                s[i]= new Officer(code, name, grade);
                break;
            }
        }

        sc.close();

        for(int j = 0;j<n;j++)
        {
            s[j].display();
        }
    }
}
