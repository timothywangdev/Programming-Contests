//package uva11821;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigDecimal;
public class Main {
	public static String removeZeros(String s){
		int index=s.length();
		for(int i=s.length()-1;i>=0;i--){
			if(s.charAt(i)!='0'){
				index=i;
				break;
			}
		}
		s=s.substring(0,index+1);
		if(s.charAt(s.length()-1)=='.'){
			s=s.substring(0,s.length()-1);
		}
		return s;
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
			  new OutputStreamWriter(System.out)));
		int T=sc.nextInt();
		for(int t=0;t<T;t++){
			BigDecimal rv=BigDecimal.ZERO;
			while(true){
				String s=sc.next();
				if(s.equalsIgnoreCase("0")){
					break;
				}
				rv=rv.add(new BigDecimal(s));
			}
			pr.printf("%s\n", removeZeros(rv.toString()));
		}
		pr.close();
	}
}
