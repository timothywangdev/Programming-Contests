//package uva11879;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextBigInteger()){
			BigInteger n=sc.nextBigInteger();
			if(n.equals(BigInteger.ZERO)){
				break;
			}
			String s=n.toString();
			String as=s.substring(s.length()-1, s.length());
			String bs;
			if(s.length()>=2){
				bs=s.substring(0,s.length()-1);
			}
			else{
				bs="0";
			}
			BigInteger a=new BigInteger(as);
			BigInteger b=new BigInteger(bs);
			b=b.subtract(a.multiply(BigInteger.valueOf(5)));
			if(b.mod(BigInteger.valueOf(17))==BigInteger.ZERO){
				System.out.println("1");
			}
			else{
				System.out.println("0");
			}
		}
	}
}
