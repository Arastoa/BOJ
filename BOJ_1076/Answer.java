import java.util.*;

public class Main {

	public enum RES1 {black , brown, red, orange, yellow, green,blue, violet, grey, white };
	public enum RES2 {black(1), brown(10),red(100), orange(1000), yellow(10000), green(100000),blue(1000000),
		violet(10000000), grey(100000000), white(1000000000);
	
		private int data;
		RES2(int n){
			this.data=n;
		}
	
	}
	
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		long result=0;
		
		for(int i= 0 ;i<2; i++){
			String str=scan.nextLine();
			result=result*10+RES1.valueOf(str).ordinal();
		}
		String str=scan.next();
		result=result*RES2.valueOf(str).data;
		System.out.println(result);
	}

}
