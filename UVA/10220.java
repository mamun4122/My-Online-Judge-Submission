import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger temp= BigInteger.ONE;
			int n= in.nextInt();
			if(n==0){
				System.out.println("1");continue;
			}
			for(long i=1;i<=n;i++)
				temp=temp.multiply(BigInteger.valueOf(i));
			String s = temp.toString();
			int sum=0;
			for(int i=0;i<s.length();i++)
			{
				sum+=s.charAt(i)-48;
			}
			System.out.println(sum);
			
			
		}
	}

}
