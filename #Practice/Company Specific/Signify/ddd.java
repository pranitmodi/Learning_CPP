import java.util.Scanner;

public class ddd {
    // private static final long MOD = 1000000007;

    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();
        
        int totalSum = calculateSumFreeSubsetSum(N);
        System.out.println(totalSum);
    }

    private static int calculateSumFreeSubsetSum(int N) {
        long subsetCount = (N + 1L) / 2L;
        long sum = subsetCount * subsetCount % MOD;
        return (int)sum;
}



}