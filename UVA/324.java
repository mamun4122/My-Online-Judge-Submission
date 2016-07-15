import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		while (in.hasNext()) {
			int n=in.nextInt();
			BigInteger ans=BigInteger.ONE;
			for(int i=1;i<=n;i++)
				ans=ans.multiply(BigInteger.valueOf(i));
			String st=ans.toString();
			int dig[]=new int[10];
			int len=st.length();
			for(int i=0;i<len;i++)
			{
				int x=st.charAt(i)-'0';
				dig[x]++;
			}
			System.out.println(n+"! --");
			System.out.println("   (0)    "+dig[0]+"    (1)    "+dig[1]+"    (2)    "+dig[2]+"    (3)    "+dig[3]+"    (4)    "+dig[4]);
			System.out.println("   (5)    "+dig[5]+"    (6)    "+dig[6]+"    (7)    "+dig[7]+"    (8)    "+dig[8]+"    (9)    "+dig[9]);
		}
	}
}
