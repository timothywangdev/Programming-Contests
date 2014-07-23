//package uva10007;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		BigInteger c[]=new BigInteger[301];
		BigInteger p[]=new BigInteger[301];
		p[0]=BigInteger.ONE;
		c[0]=BigInteger.ONE;
		for(int i=1;i<=300;i++){
			p[i]=p[i-1].multiply(BigInteger.valueOf(i));
			c[i]=c[i-1].multiply(BigInteger.valueOf((2*(2*i-1)))).divide(BigInteger.valueOf(i+1));
		}
		
		while(sc.hasNextInt()){
			int n=sc.nextInt();
			if(n==0)break;
			System.out.println(c[n].multiply(p[n]).toString());
		}
	}
}
