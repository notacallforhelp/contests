import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int k = 1;

        for(int i=1;i<=n;i++)
        {
            k*=i;
        }

        System.out.println(k);

        scanner.close();
    }
}