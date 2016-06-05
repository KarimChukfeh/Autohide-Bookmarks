import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;

class ChromeInForeground{

	public final String path = "../CPP/updatedForeground.txt";
	public static String myTask; 
	public MacroReady ready;

	public ChromeInForeground(){
		
		do{

			try
			{
				Thread.sleep(512); 
			} catch(Exception ex) 
			{
				System.out.println(ex);
			}
			
			try
			{
				FileReader taskReader = new FileReader(path);
				BufferedReader topTask = new BufferedReader(taskReader);
				myTask = topTask.readLine();
				//topTask.close();
				topTask = null;
			}catch (Exception e)
			{
			 e.printStackTrace();	
			}
			
			try
			{
				Thread.sleep(64); 
			} catch(InterruptedException ex) 
			{
				System.out.println(ex);
			}	
			
			try
			{
				if(myTask.contains("Google Chrome"))
				{	
					ready = new MacroReady();
					break;
				}else{
					break;
				}
			}catch (Exception e)
			{
				System.out.println(e);
			}
			
			try
			{
				Thread.sleep(256); 
			} catch(Exception ex) 
			{
				System.out.println(ex);
			}
			
		}while(1<2);
		
		myTask = null;
		ready = null;
	}
	

}