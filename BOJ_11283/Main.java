import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String str=scan.nextLine();
		int n=str.charAt(0)-0xac00;
		n++;
		System.out.println(n);
	}

}
