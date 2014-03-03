import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {
	private static ArrayList<BigInteger> input = new ArrayList<BigInteger>();
     public static void main(String arg[]){
    	 Scanner sc=new Scanner(System.in);
    	 while(sc.hasNext()){
    		 input.clear();
    		 while(true){
    			 int tmp=sc.nextInt();
    			 if(tmp==-999999)
    				 break;
    			 input.add(BigInteger.valueOf(tmp));
    		 }
    		 if(input.size()==0){
    			 System.out.println("0");
    			 continue;
    		 }
    		 BigInteger maximum=input.get(0);
    		 for(int i=0;i<input.size();i++){
    			 BigInteger curr=input.get(i);
    			 maximum=maximum.max(curr);
    			 for(int j=i+1;j<input.size();j++){
    				 curr=curr.multiply(input.get(j));
    				 maximum=maximum.max(curr);
    			 }
    		 }
    		 System.out.println(maximum);
    	 }
       sc.close();
     }
}
