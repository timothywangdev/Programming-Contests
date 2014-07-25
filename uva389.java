//package uva389;
import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		PrintWriter pr = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		

		while(sc.hasNext()){
			String ori=sc.next();
			int b1=sc.nextInt();
			int b2=sc.nextInt();
			BigInteger a=new BigInteger(ori,b1);
			String s=a.toString(b2).toUpperCase();

			if(s.length()<=7){
				pr.printf("%7s\n",s);
				//builder.append(String.format("%7s\n", s));
			}
			else{
				pr.printf("%7s\n", "ERROR");
				//builder.append(String.format("%7s\n", "ERROR"));
			}
			
		}
		//System.out.print(builder.toString());
		pr.close();
	}
}
