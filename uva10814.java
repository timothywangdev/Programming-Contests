//package uva10814;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;
public class Main {

	public static void main(String[] args){
		Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter pr=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int T=sc.nextInt();
		for(int t=0;t<T;t++){
			BigInteger a=sc.nextBigInteger();
			String s=sc.next();
			BigInteger b=sc.nextBigInteger();
			BigInteger gcd=a.gcd(b);
			a=a.divide(gcd);
			b=b.divide(gcd);
			pr.printf("%s / %s\n", a.toString(),b.toString());
		}
		pr.close();
	}
}
