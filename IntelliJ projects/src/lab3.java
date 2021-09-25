import java.util.Scanner;

public class lab3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        for(int i=2;i<=a;i++){
            boolean b = true;
            for(int j=2;j<i;j++){
                if(i%j==0)
                {
                    b = false;
                    break;
                }
            }
            if(b)
            {
                System.out.println(i);
            }
        }
    }
}
