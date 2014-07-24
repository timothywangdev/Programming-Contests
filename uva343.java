//package uva343;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			String as=sc.next();
			String bs=sc.next();
			int mina=1,minb=1;
			for(int i=0;i<as.length();i++){
				if(Character.isLetter(as.charAt(i))){
					mina=Math.max(mina, (int)(as.charAt(i)-'A')+10);
				}
				else{
					mina=Math.max(mina, (int)(as.charAt(i)-'0'));
				}
			}
			for(int i=0;i<bs.length();i++){
				if(Character.isLetter(bs.charAt(i))){
					minb=Math.max(minb, (int)(bs.charAt(i)-'A')+10);
				}
				else{
					minb=Math.max(minb, (int)(bs.charAt(i)-'0'));
				}
			}
			boolean equal=false;
			int base1=-1,base2=-1;
			for(int i=mina+1;i<=36;i++){
				for(int j=minb+1;j<=36;j++){
					BigInteger aa=new BigInteger(as,i);
					BigInteger bb=new BigInteger(bs,j);
					if(aa.equals(bb)){
						equal=true;
						base1=i;
						base2=j;
						break;
					}
			    }
				if(equal){
					break;
				}
			}
			if(equal){
				System.out.println(as+" (base "+Integer.toString(base1)+") = "+bs+" (base "+Integer.toString(base2)+")");
			}
			else{
				System.out.println(as+" is not equal to "+bs+" in any base 2..36");
			}
		}
	}
}
