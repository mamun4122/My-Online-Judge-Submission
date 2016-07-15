import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger temp= BigInteger.ONE;
			int n= in.nextInt();
			System.out.println(n+"!");
			if(n==0){
				System.out.println("1");continue;
			}
			for(long i=1;i<=n;i++)
				temp=temp.multiply(BigInteger.valueOf(i));
			System.out.println(temp);
			
			
		}
	}

}
