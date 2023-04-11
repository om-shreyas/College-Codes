import java.util.*;

class DistanceCalculator {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int userChoice = 1;
        while (userChoice == 1) {
            System.out.print("Enter time: ");
            int time = input.nextInt();
            System.out.print("Enter initial velocity: ");
            int initialVelocity = input.nextInt();
            System.out.print("Enter acceleration: ");
            int acceleration = input.nextInt();
            System.out.print("Enter interval: ");
            int timeInterval = input.nextInt();

            while (time <= 100) {
                float distance = (initialVelocity * time) + ((acceleration * time * time) / 2);
                System.out.println("Distance travelled in " + time + " seconds is: " + distance);
                time += timeInterval;
            }

            System.out.print("Do you want to continue?: ");
            userChoice = input.nextInt();
        }
        input.close();
    }
} 
