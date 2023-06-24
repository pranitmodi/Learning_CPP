import java.util.*;
class add_binary 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter first string: ");
        String a = sc.nextLine();
        System.out.println("Enter second string: ");
        String b = sc.nextLine();
        
        int l1 = a.length();
        int l2 = b.length();
        String big,small;
        if(l1>l2)
        {
            big = a;
            small = b;
        }
        else
        {
            big = b;
            small = a;
        }
        int lb = big.length();
        int ls = small.length();
        String f="";
        int counter = 0;
        char ch1,ch2;

        for(int i=0; i<lb; i++)
        {
            ch1 = big.charAt(lb-(i+1));
            if((ls-(i+1)) >= 0)
                ch2 = small.charAt(ls-(i+1));
            else
                ch2 = '0';

            if((ch1 == '1' && ch2 == '0' && counter == 0) || (ch1 == '0' && ch2 == '1' && counter == 0))
            {
                f = "1" + f;
            }
            else if(ch1 == '1' && ch2 == '1' && counter == 0)
            {
                f = "0" + f;
                counter = 1;
            }
            else if((ch1 == '1' && ch2 == '0' && counter == 1) || (ch1 == '0' && ch2 == '1' && counter == 1))
            {
                f = "0" + f;
                counter = 1;
            }
            else if(ch1 == '1' && ch2 == '1' && counter == 1)
            {
                f = "1" + f;
                counter = 1;
            }
            else if(ch1 == '0' && ch2 == '0' && counter == 1)
            {
                f = "1" + f;
                counter = 0;
            }
            else if(ch1 == '0' && ch2 == '0' && counter == 0)
            {
                f = "0" + f;
            }
        }
        if(counter == 1)
        {
            f = "1" + f; 
        }
        
    System.out.println("Addition result is: " + f);
    }
}