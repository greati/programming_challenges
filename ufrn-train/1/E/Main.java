import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    public static void main (String [] args) {
        
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> numbers = new ArrayList<Integer>();

        while (sc.hasNext()) {
            
            int n = sc.nextInt();

            if (n == -999999) {
                
                BigInteger prodTemp;
                BigInteger maxProd = BigInteger.valueOf(numbers.get(0)); 

                for (int i = 0; i < numbers.size(); ++i) {
                    prodTemp = BigInteger.valueOf(1);
                    for (int j = i; j < numbers.size(); ++j) {
                        prodTemp = prodTemp.multiply(BigInteger.valueOf(numbers.get(j)));
                        if (prodTemp.compareTo(maxProd) == 1)
                            maxProd = prodTemp;
                    }
                }

                System.out.println(maxProd.toString());
                numbers.clear(); 
            } else numbers.add(n);
        }    
    }
}
