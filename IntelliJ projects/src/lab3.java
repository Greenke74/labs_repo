import java.util.Scanner;

public  class lab3 {
    public static Scanner s = new Scanner(System.in);

    public static void exercise1() {
        int user_value;
        System.out.println("Вкажіть число ");
        if (!s.hasNextInt()) {
            System.out.println("Введене не ціле число");
        } else {
            user_value = s.nextInt();
            if (user_value % 2 == 0) {
                System.out.println("Число парне");
            } else {
                System.out.println("Число не парне");
            }
        }
    }

    public static void exercise2(){
        int[] values={0,0,0};
        System.out.println("Введіть перше число");
        values[0] = s.nextInt();
        System.out.println("Введіть друге число");
        values[1] = s.nextInt();
        System.out.println("Введіть третє число");
        values[2] = s.nextInt();
        int temp;
        for(int i=0;i<values.length;i++){
            for(int j=0;j<values.length-i-1;j++){
                if(Math.abs(values[j])>Math.abs(values[j+1])){
                    temp=values[j];
                    values[j]=values[j+1];
                    values[j+1]=temp;
                }
            }
        }
        System.out.println("Найменше за модулем число " + values[0]);
    }

    public static void exercise3(){
        Scanner s = new Scanner(System.in);
        System.out.println("Введіть слово з п'яти букв");
        String value = s.nextLine();
        int length;
        length=value.length();
        if(length!=5){
            System.out.println("Помилка!");
            return;
        }
        else {
            String lowerCaseVal=value.toLowerCase();
            for(int i=0;i<length-length/2;i++){
                if(lowerCaseVal.charAt(i)!=lowerCaseVal.charAt(length-i-1)){
                    System.out.println("Слово " + value + " не є паліднромом");
                    return;
                }
            }
        }
        System.out.println("Слово " + value + " є паліднромом");
    }

    public static void exercise4(){
        System.out.println("Введіть ціле число");
        int result=0, value = s.nextInt();
        for(int i=1;i<=value;i++){
            result+=(i*(i+1)*2*i);
        }
        System.out.println("Результат: " + result);
    }

    public static void exercise5(){
        String val = s.nextLine();
        String val2 = s.nextLine();
        char for_delete = val2.charAt(0);
        char[] digits =  val.toCharArray();
        String res="";
        for(char c : digits){
            if(c != for_delete){
                res+=c;
            }
        }
        System.out.println(res);
    }

    public static void exercise6(){
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

    public static void main(String[] args) {
        exercise1();
        exercise2();
        exercise3();
        exercise4();
        exercise5();
        exercise6();
    }
}
