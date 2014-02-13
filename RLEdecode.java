import java.util.Scanner;

public class RLEdecode {
	public static void main(String[] args) {
		System.out.println("enter the encoded string(begin with $ and enter character followed by number):");
		Scanner scan=new Scanner(System.in);
		String str=scan.nextLine();
		int rep=0,i=1;
		for(i=1;i<str.length()-1;i++)
		   {
		    try
		    { 
		    rep=Integer.parseInt(str.valueOf(str.charAt(i+1)),10);
		    }
		    catch(NumberFormatException e){
		    System.out.print(str.charAt(i));
		    continue;
		    }
		    for(int j=0;j<rep;j++)
		    	System.out.print(str.charAt(i));
		    i++;
		   }
	if(i==str.length()-1)
	{
		System.out.println(str.charAt(i));
	}
	}
}