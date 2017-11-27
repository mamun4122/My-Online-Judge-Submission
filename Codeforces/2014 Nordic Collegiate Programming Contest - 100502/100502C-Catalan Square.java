import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    static BigInteger[] cat = new BigInteger[5010];
    public static void main(String[] args) {
        cat[0] = BigInteger.ONE;
        for(int i = 1; i < 5001; i++)
        {
            cat[i] = cat[i-1];
            cat[i] = cat[i].multiply(BigInteger.valueOf(4*i-2));
            cat[i] = cat[i].divide(BigInteger.valueOf(i+1));
        }
        // TODO Auto-generated method stub
        Scanner in=new Scanner(System.in);
        while (in.hasNext())
        {
            int n = in.nextInt();
//            System.err.println(n);
            BigInteger ans = BigInteger.ZERO;
            for(int i = 0; i <= n; i++){
                BigInteger res = cat[i];
                res = res.multiply(cat[n-i]);
                ans = ans.add(res);
            }
            System.out.println(ans);
        }
    }

}