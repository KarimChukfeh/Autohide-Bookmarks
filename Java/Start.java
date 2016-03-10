class Start{

	public static LinkedQueue<ChromeInForeground> q;
	

	
	public static void main(String[] args)
	{
	
		do{
			
			try
			{
				q = new LinkedQueue<ChromeInForeground>();
				int i = 0;
				do
				{
					q.enqueue(new ChromeInForeground());
					i++;
				}while(i<32);
				
			}catch(Exception e)
			{
				System.out.println(e + "1");
			}
			
			try
			{
				int j = 0;
				do
				{
					q.dequeue();
					try
					{
						Thread.sleep(128); 
					} catch(Exception ex) 
					{
						System.out.println(ex  + "2");
					}
					j++;
				}while(j<32);
			}catch(Exception e)
			{
				System.out.println(e  + "3");
			}
	
			try
			{
				Thread.sleep(128); 
			} catch(Exception ex) 
			{
				System.out.println(ex  + "2");
			}
			
		}while(1<2);

	}

}