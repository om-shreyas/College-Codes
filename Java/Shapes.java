import java.util.*;
interface shape{
    public void area();
}
class Rectangle implements shape{
    double side1 = 0;
    double side2 = 0;
    Rectangle(double s1,double s2)
    {
        side1=s1;
        side2=s2;
    }
    public void area()
    {
        double area = side1*side2;
        System.out.println(area);
    }
}
class Cuboid implements shape{
    double side1 = 0;
    double side2 = 0;
    double side3 = 0;
    Cuboid(double s1,double s2,double s3){
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
    public void area()
    {
        double area = 2*side1*side2+2*side1*side2+2*side2*side3;
        System.out.println(area);
    }
}

class Shapes{
    public static void main(String[] args) {
        Rectangle r = new Rectangle(25.5,52.5);
        Cuboid c = new Cuboid(5.5, 89.5, 85.22);
        r.area();
        c.area();
    }
}