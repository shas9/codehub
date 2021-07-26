import java.util.Scanner;

class series
{
	public static void main(String args[])
	{
		int test, x, y, z;
		
		Scanner in = new Scanner(System.in);
		
		test = in.nextInt();
		
		for(y = 1; y <= test; y++)
		{
			x = in.nextInt();
			
			if(x % 2 == 0)
			{
				z = -(x/2);
			}
			else
			{
				z = -(x/2) + 1;
			}
			
			System.out.println(z);
			
		}
	}
}