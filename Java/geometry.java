import java.util.*;

interface Shape {
    void calculate();
}

class Rectangle implements Shape {
    double dim1, dim2;
    
    Rectangle() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the rectangle: ");
        dim1 = sc.nextDouble();
        System.out.println("Enter the breadth of the rectangle: ");
        dim2 = sc.nextDouble();
    }
    
    public void calculate() {
        System.out.println("Area of Rectangle: " + dim1 * dim2);
    }
}

class Cuboid implements Shape {
    double dim1, dim2, dim3;
    
    Cuboid() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the cuboid:");
        dim1 = sc.nextDouble();
        System.out.println("Enter the breadth of the cuboid: ");
        dim2 = sc.nextDouble();
        System.out.println("Enter the height of the cuboid:");
        dim3 = sc.nextDouble();
    }
    
    public void calculate() {
        System.out.println("Volume of Cuboid: " + dim1 * dim2 * dim3);
    }
}

class geometry {
    public static void main(String args[]) {
        Rectangle r = new Rectangle();
        Cuboid c = new Cuboid();
        r.calculate();
        c.calculate();
    }
}
