import java.util.Scanner;

public class Main {
	public static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNext()) {
			String str = scan.next();
			String[] nums = str.split("\\(");
			String[] numss = str.split("\\.");
			int mother = 0;
			for (int i = 0; i < nums[1].length() - 1; i++) {
				mother *= 10;
				mother += 9;
			}
			for (int i = 0; numss[1].charAt(i) != '('; i++) {
				mother *= 10;
			}
			int sChild;
			if (numss[1].length() - 1 == nums[1].length()) {
				sChild = Integer.parseInt(numss[1].replaceAll("\\(", "").replaceAll("\\)", ""));
			} else {
				sChild = Integer.parseInt(numss[1].replaceAll("\\(", "").replaceAll("\\)", ""))
						- Integer.parseInt(numss[1].substring(0, numss[1].indexOf('(')));
			}
			sChild+=Integer.parseInt(numss[0])*mother;
			int gd = gcd(mother, sChild);
			System.out.println(str + " = " + (sChild / gd) + " / " + (mother / gd));
		}
	}

}
