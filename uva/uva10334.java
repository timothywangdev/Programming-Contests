//package uva10334;
import java.util.Scanner;
import java.math.BigInteger;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		BigInteger[] fib=new BigInteger[1001];
		fib[0]=BigInteger.valueOf(1);
		fib[1]=BigInteger.valueOf(2);
		for(int i=2;i<=1000;i++){
			fib[i]=fib[i-1].add(fib[i-2]);
		}
		while(sc.hasNextInt()){
			int k=sc.nextInt();
			System.out.println(fib[k].toString());
		}
	}
}
