import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static BigInteger[] cache;
	static int n;
	static BigInteger mo=BigInteger.valueOf(-1);
	static BigInteger tiling(int index){
		if(index==n){
			return BigInteger.ONE;
		}
		if(index > n ) return BigInteger.ZERO;
		
		if(!cache[index].equals(mo)) return cache[index];
		
		cache[index]=BigInteger.ZERO;
		cache[index]=cache[index].add(tiling(index+1).add(tiling(index+2)).add(tiling(index+2)));
		return cache[index];
	}
	
	static void setting(){
		cache=new BigInteger[251];
		for(int i=0 ; i<251 ; i++)
			cache[i]=BigInteger.valueOf(-1);
	}
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		
		while(scan.hasNext()){
			n=scan.nextInt();
			setting();
			
			System.out.println(tiling(0));
		}
	}
}
