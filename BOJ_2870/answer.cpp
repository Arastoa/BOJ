import java.awt.Container;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt(); ArrayList<BigInteger> vt = new ArrayList<BigInteger>();
		while (n-- > 0){
			String str=scan.next();
			for (int i = 0; i < str.length(); i++){
				BigInteger temp=BigInteger.ZERO;
				if (str.charAt(i) >= '0' && str.charAt(i) <= '9'){
					while (i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9'){
						temp=temp.multiply(BigInteger.TEN); temp=temp.add(BigInteger.valueOf((long)str.charAt(i++)-'0'));
					}

					vt.add(temp);
				}
			}
		}
		Collections.sort(vt);
		for(int i=0 ; i< vt.size() ; i++)
			System.out.println(vt.get(i));
	}
}
