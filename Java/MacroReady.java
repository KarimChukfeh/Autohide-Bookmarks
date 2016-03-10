import java.awt.Container;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.*;
import java.awt.event.InputEvent;

class MacroReady{

		public static MouseInfo mouse;
		
		public MacroReady()
		{
			do{
				try
				{
					Thread.sleep(64); 
				} catch(Exception ex) 
				{
					System.out.println(ex);
				}	
				try
				{	
					if((mouse.getPointerInfo().getLocation().getY() < 62)
					&&(mouse.getPointerInfo().getLocation().getY() > 0))
					{
					
						try 
						{
							
							Robot robot = new Robot();
							robot.keyPress(KeyEvent.VK_CONTROL);
							robot.keyPress(KeyEvent.VK_SHIFT);
							robot.keyPress(KeyEvent.VK_B);		
							robot.keyRelease(KeyEvent.VK_B);
							robot.keyRelease(KeyEvent.VK_SHIFT);
							robot.keyRelease(KeyEvent.VK_CONTROL);
					
						} catch (Exception e) 
						{

							e.printStackTrace();

						}
						break;
					}	
					
				}catch(Exception e)
				{
					System.out.println(e);
				}
				try
				{
					Thread.sleep(128); 
				} catch(InterruptedException ex) 
				{
					System.out.println(ex);
				}	
			}while(1<2);
			
			do{
				try
				{
					Thread.sleep(64); 
				} catch(Exception ex) 
				{
					System.out.println(ex);
				}	
				try
				{	
					if(mouse.getPointerInfo().getLocation().getY() > 88)
					{
						try 
						{
							
							Robot robot = new Robot();
							robot.keyPress(KeyEvent.VK_CONTROL);
							robot.keyPress(KeyEvent.VK_SHIFT);
							robot.keyPress(KeyEvent.VK_B);		
							robot.keyRelease(KeyEvent.VK_B);
							robot.keyRelease(KeyEvent.VK_SHIFT);
							robot.keyRelease(KeyEvent.VK_CONTROL);
					
						} catch (Exception e) 
						{
							e.printStackTrace();
						}
						break;
					}	
					
				}catch(Exception e)
				{
					System.out.println(e);
				}
				try
				{
					Thread.sleep(1000); 
				} catch(Exception ex) 
				{
					System.out.println(ex);
				}	
			}while(1<2);
			
			mouse = null;
		}

}