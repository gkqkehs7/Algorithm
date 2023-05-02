import java.util.Scanner;

public class Main2229 {
    public static void main(String[] args) {
        int arr[] = new int[10001];
        int dp[] = new int[10001];

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=1; i<=n; i++) {
            int input = sc.nextInt();
            arr[i] = input;
        }

        for(int i=0; i<1001; i++) {
            dp[i] = 0;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                int max_value = 0;
                int min_value = 100001;
    
                for(int k = 0; k < j; k++) {
                    int temp = arr[i - k];
                    max_value = Math.max(max_value, temp);
                    min_value = Math.min(min_value, temp);
                }
    
                dp[i] = Math.max(dp[i], dp[i-j] + (max_value - min_value));
           }
        }

        System.out.println(dp[n]);
    }
}