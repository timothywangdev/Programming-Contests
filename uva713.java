//package uva713;

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int t=0;t<T;t++){
			BigInteger a=sc.nextBigInteger();
			BigInteger b=sc.nextBigInteger();
			String as=new StringBuffer(a.toString()).reverse().toString();
			String bs=new StringBuffer(b.toString()).reverse().toString();
			BigInteger c=new BigInteger(as);
			BigInteger d=new BigInteger(bs);
			c=c.add(d);
			String cs=new StringBuffer(c.toString()).reverse().toString();
			BigInteger dd=new BigInteger(cs);
			System.out.println(dd.toString());
		}
	}
}
