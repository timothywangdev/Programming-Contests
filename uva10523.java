//package uva10523;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextInt()){
			int N=sc.nextInt();
			int A=sc.nextInt();
			BigInteger rv=BigInteger.ZERO;
			for(int i=1;i<=N;i++){
				rv=rv.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(A).pow(i)));
			}
			System.out.println(rv);
		}
	}
}
