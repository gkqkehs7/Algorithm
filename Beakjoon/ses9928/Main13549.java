import java.util.Scanner;

public class Main13549 {
    static int[][] dp = new int[251][251];

    public static void main(String args[]) {

        for(int i=1; i<=250; i++) {
            for(int j=1; j<=250; j++) {
                if(i==1 || j==1) {
                    dp[i][j] = 1;
                } else  {
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10000019;
                }
               
            }
        }

        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                System.out.print(dp[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }

    
    }
}
