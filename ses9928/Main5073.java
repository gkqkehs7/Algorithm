import java.util.Scanner;

public class Main5073 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(true) {
			int input1 = sc.nextInt();
			int input2 = sc.nextInt();
			int input3 = sc.nextInt();
			
			if(input1 == 0 && input2 == 0 && input3 == 0) {
				break;
			}

			int max_len = Math.max(input1, input2);
			max_len = Math.max(max_len, input3);
			
			if(max_len >= input1 + input2) {
				System.out.println("Invalid");
				continue;
			}

			int first = 0;
			int second = 0;
			int third = 0;

			if(input1 == input2) {
				first += 1;
			} 

			if(input1 == input3) {
				first += 1;
			}

			if(input2 == input3) {
				second += 1;
			}
			
			if(first == 2) {
				System.out.println("Equilateral");
			} else if(first == 1 || second == 1) {
				System.out.println("Isosceles");
			} else {
				System.out.println("Scalene");
			}
			
		}
	}
	
}
