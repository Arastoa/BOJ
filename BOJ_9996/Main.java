import java.util.Scanner;
import java.util.regex.Pattern;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        String source="^"+scan.next()+"$";
        source=source.replace("*", "(.*)");
        while(n-->0){
            String target=scan.next();
            if(Pattern.matches(source, target))
                System.out.println("DA");
            else
                System.out.println("NE");
        }
    }
}
