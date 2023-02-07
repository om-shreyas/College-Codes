import java.util.Scanner;
public class voters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vote: ");
        int n= sc.nextInt();
        int v[] = new int[n];
        for(int i = 0;i<n;i++)
        {
            System.out.print("Enter your vote: ");
            v[i]=sc.nextInt();
        }

        sc.close();
        
        int c1=0;
        int c2=0;
        int c3=0;
        int c4=0;
        int c5=0;
        for(int i = 0;i<n;i++)
        {
            switch(v[i])
            {
                case 1:
                c1++;
                break;
                case 2:
                c2++;
                break;
                case 3:
                c3++;
                break;
                case 4:
                c4++;
                break;
                case 5:
                c5++;
                break;
                default:
                break;
            }
        }
        
        System.out.println("Candidate 1 got: "+c1);
        System.out.println("Candidate 2 got: "+c2);
        System.out.println("Candidate 3 got: "+c3);
        System.out.println("Candidate 4 got: "+c4);
        System.out.println("Candidate 5 got: "+c5);
        System.out.println("No. of wasted votes: "+(n-c1-c2-c3-c4-c5));
    }
}
