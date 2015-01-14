//package uva10551;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextInt()){
			int base=sc.nextInt();
			if(base==0)break;
			BigInteger a=new BigInteger(sc.next(),base);
			BigInteger b=new BigInteger(sc.next(),base);
			System.out.println(a.mod(b).toString(base));
		}
	}
}
