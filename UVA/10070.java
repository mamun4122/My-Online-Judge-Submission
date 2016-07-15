import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static boolean leap(BigInteger n)
	{
		if(n.mod(BigInteger.valueOf(400))==BigInteger.ZERO)return true;
		if(n.mod(BigInteger.valueOf(100))==BigInteger.ZERO)return false;
		if(n.mod(BigInteger.valueOf(4))==BigInteger.ZERO)return true;
		return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int flag=0;
		while (in.hasNext()) {
			if(flag==1)System.out.println("");
			flag=1;
			BigInteger input=in.nextBigInteger();
			int f=0,l=0;
			if(leap(input)==true)
			{
				f=1;
				l=1;
				System.out.println("This is leap year.");
			}
			if(input.mod(BigInteger.valueOf(15))==BigInteger.ZERO)
			{
				f=1;
				System.out.println("This is huluculu festival year.");
			}
			if(l==1&&input.mod(BigInteger.valueOf(55))==BigInteger.ZERO)
			{
				f=1;
				System.out.println("This is bulukulu festival year.");
			}
			if(f==0)System.out.println("This is an ordinary year.");
		}
	}
}
