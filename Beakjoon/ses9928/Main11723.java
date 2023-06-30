import java.util.*;


public class Main11723 {
    public static void main(String args[]) {
        boolean arr[] = new boolean[21];
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();

        for(int i=0; i<m; i++) {
            String command = sc.next();
            int input = sc.nextInt();

            if(command == "add") {
                if(arr[input] != false) {
                    arr[input] = true;
                }
            } else if(command == "remove") {
                if(arr[input] != false) {
                    arr[input] = false;
                }
            } else if(command == "check") {
                if(arr[input] != false) {
                    System.out.print(1);
                } else {
                    System.out.print(0);
                }
            } else if(command == "toggle") {
                if(arr[input] != false) {
                    arr[input] = false;
                } else {
                    arr[input] = true;
                }
            } else if(command == "all") {
                for(int j=1; j<21; j++) {
                    arr[j] = true;
                }
            } else if(command == "empty") {
                for(int j=1; j<21; j++) {
                    arr[j] = false;
                }
            }
        }
    }
}
