import java.util.LinkedList;
import java.util.Scanner;



public class UVA10528_MajorScales {
	
	static String[] noteNames = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	
	static boolean[] major = {true, false, true, false, true, true, false, true, false, true, false, true};
	
	static boolean[][] scales = new boolean[12][12]; 
	
	/*
	 * 0 - C
	 * 1 - C#
	 * 2 - D
	 * 2 - D#
	 * ...
	 */
	static int indexOf(String note) {
		int val = note.charAt(0) - 'C';
		val *= 2;
		if (note.length() == 2) val++;
		
		return val;
	}

	static String[] scalesOfNotes(boolean[] notes) {
		LinkedList<String> scaleNames = new LinkedList<String>();
		for (int i = 0; i < scales.length; i++) {
			assert(notes.length == scales[i].length);
			boolean isOfScale = true;
			for (int j = 0; j < scales[i].length; j++) {
				if (notes[j] && !scales[i][j]) {
					isOfScale = false;
					break;
				}
			}
			
			if (isOfScale) scaleNames.add(noteNames[i]);
		}
		
		return (String[]) scaleNames.toArray();
	}
	
	public static void main(String[] args) {
		
		String line;
		String[] tokens;
		Scanner scanner = new Scanner(System.in);
		boolean[] notes = new boolean[12];
		
		// prepare scales
		for (int i = 0; i < major.length; i++) {
			int c = 0;
			for (int j = i; j < scales[i].length; j++) {
				scales[i][c++] = major[j];
			}
			
			for (int j = 0; j < i; j++) {
				scales[i][c++] = major[j];
			}
		}
		
		// end prepare scales
		
		while (true) {
			line = scanner.nextLine();
			if (line.equals("END")) break;
			
			tokens = line.split(" ");
			for (String token : tokens) {
				notes[indexOf(token)] = true;
				scalesOfNotes(notes);
			}
		}
		
		scanner.close();

	}

}
