import java.util.*;

public class  {
	static Scanner scanner = new Scanner(System.in);
	static Vector<String> citynames = new Vector();
	static int citycount = 0;
	static String cityname1, cityname2;
	static int citynum1, citynum2;
	public static void main(String args[]) {
		while (true) {
			cityname1 = scanner.next();
			System.out.println("city1: " + cityname1);
			if (cityname1.equals("#")) break;
			cityname2 = scanner.next();
			System.out.println("city1: " + cityname2);
		} // end read statements
	} // end main
}