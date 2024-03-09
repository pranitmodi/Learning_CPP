import java.util.Scanner;

public class ddd {
    private static final long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long sum = 0;

        for (int i = 1; i <= N; i += 2) {
            sum += i;
            sum %= MOD; // To handle the large output, take modulo at each step
        }

        System.out.println(sum);
    }
}