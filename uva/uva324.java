//package uva324;

import java.util.Scanner;
import java.math.BigInteger;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(true){
			int N=sc.nextInt();
			if(N==0)break;
			int[] count=new int[10];
			for(int i=0;i<10;i++)count[i]=0;
			BigInteger fa=BigInteger.ONE;
			for(int i=1;i<=N;i++){
				fa=fa.multiply(BigInteger.valueOf(i));
			}
			String s=fa.toString();
			for(int i=0;i<s.length();i++){
				count[(int)(s.charAt(i)-'0')]++;
			}
			System.out.println(N+"! --");
			for(int i=0;i<=4;i++){
				System.out.print("   ");
				System.out.print("("+i+")");
				System.out.print("   ");
				System.out.print(count[i]);
			}
			System.out.println();
			for(int i=5;i<=9;i++){
				System.out.print("   ");
				System.out.print("("+i+")");
				System.out.print("   ");
				System.out.print(count[i]);
			}
			System.out.println();
		}
	}
}
