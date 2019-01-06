import java.util.*;


class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		TreeMap<String, String> map;
		int q,a;
		String in[];
		scan.useDelimiter("\n");
		in = scan.nextLine().split(" ");
		a = Integer.parseInt(in[0]);
		q = Integer.parseInt(in[1]);
		
		map = new TreeMap<String, String>();
		
		for( int i=0 ;i<a; i++ ){
			in = scan.nextLine().split(" ");
			map.put(in[0], in[1]);
		}
		
		for( int i=0 ;i<q; i++ ){
			in = scan.nextLine().split(" ");
			if( in.length == 1 ){
				
				System.out.println("not found");
			} else{
				if( map.get(in[0]).equals(in[1])){
					System.out.println("ok");
				} else {
					System.out.println("wrong");
				}
				
			}
		}
	}

}
