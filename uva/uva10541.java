//package uva10541;

import java.util.Arrays;
import java.util.Scanner;
import java.math.BigInteger;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		BigInteger[][] bi=new BigInteger[201][201];
		for(int n=0;n<=200;n++){
			for(int k=0;k<=200;k++){
				if(k==0){
					bi[n][k]=BigInteger.valueOf(1);
				}
				else{
					if(k<n){
						bi[n][k]=bi[n-1][k-1].add(bi[n-1][k]);
					}
					else if(k==n){
						bi[n][k]=BigInteger.valueOf(1);
					}
					else{
						bi[n][k]=BigInteger.valueOf(0);
					}
				}
			}
		}
		int T=sc.nextInt();
		for(int t=0;t<T;t++){
			int N=sc.nextInt();
			int K=sc.nextInt();
			int sum=0;
			for(int i=0;i<K;i++){
				int tmp=sc.nextInt();
				sum+=tmp;
			}
			System.out.println(bi[N-sum+1][K].toString());
		}
	}
}
