import java.util.Scanner;
public class Tempreature_Calendar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter The number of cities: ");
        int cities = sc.nextInt();
        System.out.print("Enter The number of days: ");
        int days = sc.nextInt();
        int table[][] = new int[cities][days];
        int max_temp=-9999;
        int max_temp_city=0;
        int max_temp_day=0;
        int low_temp=9999;
        int low_temp_city=0;
        int low_temp_day=0;
        for(int i=0;i<cities;i++)
        {
            System.out.println("Enter tempreature for city "+i);
            for(int j=0;j<days;j++)
            {
                System.out.print("Enter the tempreature for day "+j+" : ");
                table[i][j]=sc.nextInt();
                if(table[i][j]>max_temp)
                {
                    max_temp = table[i][j];
                    max_temp_city = i;
                    max_temp_day = j;
                }
                if(table[i][j]<low_temp)
                {
                    low_temp = table[i][j];
                    low_temp_city = i;
                    low_temp_day = j;
                }
            }
        }
        System.out.println("The Hottes days was "+max_temp_day+" in city "+max_temp_city);
        System.out.println("The Hottes days was "+low_temp_day+" in city "+low_temp_city);
        sc.close();
    }
}
