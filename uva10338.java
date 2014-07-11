//package uva10338;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	private static BigInteger factorial(int n){
		BigInteger rv=BigInteger.ONE;
		for(int i=2;i<=n;i++){
			rv=rv.multiply(BigInteger.valueOf(i));
		}
		return rv;
	}
	public static void main(String[] args){
		int T;
		String s;
		Scanner sc=new Scanner(System.in);
		T=sc.nextInt();
		s=sc.nextLine();
		for(int t=0;t<T;t++){
			s=sc.nextLine();
			int[] count=new int[26];
			for(int i=0;i<26;i++)count[i]=0;
			for(int i=0;i<s.length();i++){
				count[(int)(s.charAt(i)-'A')]++;
			}
			BigInteger den=BigInteger.ONE;
			for(int i=0;i<26;i++){
				if(count[i]>0){
					den=den.multiply(factorial(count[i]));
				}
			}
			//System.out.println("Debug "+den.toString());
			den=factorial(s.length()).divide(den);
			System.out.println("Data set "+(t+1)+": "+den.toString());
		}
	}
}
