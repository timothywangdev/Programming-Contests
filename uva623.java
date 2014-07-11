//package uva623;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextInt()){
			int N=sc.nextInt();
			BigInteger n=BigInteger.ONE;
			for(int i=2;i<=N;i++){
				n=n.multiply(BigInteger.valueOf(i));
			}
			System.out.println(N+"!");
			System.out.println(n.toString());
		}
	}
}
