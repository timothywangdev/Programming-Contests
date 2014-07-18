//package uva763;

import java.util.Scanner;
import java.math.BigInteger;
public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s1,s2,tmp;
		
		BigInteger[] fib=new BigInteger[200];
		fib[0]=BigInteger.ONE;
		fib[1]=BigInteger.valueOf(2);
		for(int i=2;i<200;i++){
			fib[i]=fib[i-2].add(fib[i-1]);
		}
		boolean firstTest=true;
		while(sc.hasNextLine()){
			s1=sc.nextLine();
			s2=sc.nextLine();
			if(sc.hasNextLine()){
				tmp=sc.nextLine();
			}
			if(firstTest){
				firstTest=false;
			}
			else{
				System.out.println();
			}
			BigInteger n1=BigInteger.ZERO,n2=BigInteger.ZERO;
			for(int i=s1.length()-1;i>=0;i--){
				if(s1.charAt(i)=='1'){
					n1=n1.add(fib[s1.length()-i-1]);
				}
			}
			for(int i=s2.length()-1;i>=0;i--){
				if(s2.charAt(i)=='1'){
					n2=n2.add(fib[s2.length()-i-1]);
				}
			}
			n1=n1.add(n2);
			int pos=199;
			String rv = "";
			boolean first=true;
			if(n1.equals(BigInteger.ZERO)){
				rv+="0";
			}
			while(pos>=0){
				int i;
				for(i=pos;i>=0;i--){
					if(fib[i].compareTo(n1)<=0){
						n1=n1.subtract(fib[i]);
						pos=i-1;
						if(first){
							first=false;
						}
						rv+="1";
						break;
					}
					else{
						if(!first){
							rv+="0";
						}
					}
				}
				pos=i-1;
			}
			//rv= new StringBuffer(rv).reverse().toString();
			System.out.println(rv);
		}
	}
}
