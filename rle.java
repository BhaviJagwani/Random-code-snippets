import java.util.Scanner;
class bhavi {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a string of characters");
		String str=sc.nextLine();
		int count=1;
		int len=str.length();
		System.out.print("$");
		for(int i=0; i<len-1; i++)                      
		  { if(str.charAt(i)==str.charAt(i+1))  
		     count++;
		    else if (count==1) 
                                              {System.out.print(str.charAt(i));}
		          else if ( count>1)
                                                   { System.out.print(count);
                                                    System.out.print(str.charAt(i));   
		                    count=1;}
                                   }
		   if(count>1)                                              
		   System.out.print(count);
		   System.out.print(str.charAt(len-1));
	}

}
