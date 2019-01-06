import java.math.BigInteger;
import java.util.Scanner;


public class UVa10079_PizzaCutting {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		BigInteger n;
		while (true) {
			try {
				n = scanner.nextBigInteger();
			} catch (Exception e) {
				break;
			}
			System.out.println(
					n.multiply(n.add(BigInteger.ONE)).add(BigInteger.ONE));
		}
		scanner.close();
	}

}
