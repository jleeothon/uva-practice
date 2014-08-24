import java.util.Scanner;


public class UVA1094_MotherBear {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		int difference = 'a' - 'A';
		int comparison;
		boolean isPalindrome;
		
		while (true) {
			String s = scanner.nextLine();
			if (s.equals("DONE")) break;
			
			isPalindrome = true;
			int i = 0;
			int j = s.length() - 1;
			while (i < j) {
				if (!Character.isLetter(s.charAt(i))) {
					i++;
					continue;
				}
				
				if (!Character.isLetter(s.charAt(j))) {
					j--;
					continue;
				}
				
				comparison = Character.compare(s.charAt(i), s.charAt(j)); 
				if (!(comparison == 0 || comparison == difference || comparison == -difference)) {
					isPalindrome = false;
				}
				
				i++;
				j--;
			}
			
			
			if (isPalindrome) {
				System.out.println("You won't be eaten!");
			} else {
				System.out.println("Uh oh..");
			}
		}
		
		scanner.close();
	}

}
