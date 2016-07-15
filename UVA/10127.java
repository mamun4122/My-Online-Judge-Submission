import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger temp= BigInteger.ONE;

			int n= in.nextInt();
			//System.err.println(n);
			BigInteger val=BigInteger.valueOf(n);
			//System.err.println(val);
			int cnt=1;
			while (true) {
				//System.err.println(temp);
				if(temp.mod(val)==BigInteger.ZERO)
					break;
				else {
					cnt++;
					temp=temp.multiply(BigInteger.valueOf(10));
					temp=temp.add(BigInteger.ONE);
					
				}
			}
			System.out.println(cnt);
			
			
			
			
		}
	}

}