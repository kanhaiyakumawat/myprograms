import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import org.markdown4j.*;

/**
 * 
 */

/**
 * @author kkumawat
 *
 */
public class ParsePost {
	/**
	 * @param source
	 * @param destination
	 */
	public ParsePost(File source, File destination) {
		super();
		this.source = source;
		this.destination = destination;
	}
	private	File source;
	private File destination;
	private File post = new File("temp_file");
	private String Title;
	private String Author;
	private String Date;
	private boolean isPublished;
	public boolean parse() throws IOException
	{
		Scanner scanner = new Scanner(new FileReader(source));
		if(scanner.hasNextLine())
		{
			Scanner scanline = new Scanner(scanner.nextLine());
			scanline.useDelimiter(":");
			if(scanline.hasNext())
			{
				if(scanline.next().trim().equals("Title"))
				{
					setTitle(scanline.next().trim());
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			//error
			return false;
		}
		if(scanner.hasNextLine())
		{
			Scanner scanline = new Scanner(scanner.nextLine());
			scanline.useDelimiter(":");
			if(scanline.hasNext())
			{
				if(scanline.next().trim().equals("Date"))
				{
					setDate(scanline.next().trim());
				}
			}
		}
		else
		{
			//error
			return false;
		}
		if(scanner.hasNextLine())
		{
			Scanner scanline = new Scanner(scanner.nextLine());
			scanline.useDelimiter(":");
			if(scanline.hasNext())
			{
				if(scanline.next().trim().equals("Author"))
				{
					setAuthor(scanline.next().trim());
				}
			}
		}
		else
		{
			//error
			return false;
		}
		if(scanner.hasNextLine())
		{
			Scanner scanline = new Scanner(scanner.nextLine());
			scanline.useDelimiter(":");
			if(scanline.hasNext())
			{
				if(scanline.next().trim().equals("Published"))
				{
					if(scanline.next().trim().equals("true"))
					{
						setIsPublished(true);
					}
					else
					{
						setIsPublished(false);
					}
				}
			}
		}
		else
		{
			//error
			return false;
		}
		if(scanner.hasNextLine())
		{
			//Scanner scanline = new Scanner(scanner.nextLine());
			System.out.println(scanner.nextLine());
			/*if(scanner.nextLine().equals("--"))
			{
					System.out.println("this post has content");
			}*/
		}
		else
		{
			//error
			return false;
		}
		System.out.println("Parsing over");
		//post.delete();
		post.createNewFile();
		FileWriter fw = new FileWriter(post.getName());
		while(scanner.hasNextLine())
		{	
			String nextline = scanner.nextLine();
			fw.write(nextline+"\n");
		}
		fw.close();
		printPost();
		return true;
	}
	public boolean publish() throws IOException
	{
		System.out.println("Starting the publishing");
		if(!getIsPublished())
		{
			System.out.println("This Post is still saved as draft and not ready to be published");
			return false;
		}
		else
		{
			File temp = new File(getDestination().getPath()+System.getProperty("file.separator")+"posts");
			if(temp.exists() || temp.mkdir())
			{
				File date_dir = new File(temp.getPath()+System.getProperty("file.separator")+getDate());
				if(date_dir.exists() || date_dir.mkdir())
				{
					File post_file = new File(date_dir.getPath()+System.getProperty("file.separator")+getSource().getName()+".html");
					if(post_file.exists())
					{
						System.out.println("Post Already published");
					} 
					else
					{
						try {
							if(post_file.createNewFile())
							{					
								Markdown4jProcessor mrkd = new Markdown4jProcessor();
								String html = mrkd.process(post);
								FileWriter fw = new FileWriter(post_file);
								fw.write(html);
								fw.close();
								post.delete();
								File index_file = new File(getDestination().getPath()+"\\index.html");
								if(index_file.exists() || index_file.createNewFile())
								{
									PrintWriter fw1 = new PrintWriter(new FileWriter(index_file.getPath(),true));
									fw1.append("<a href="+post_file.getAbsolutePath()+">"+getSource().getName()+"</a><br/>");
									fw1.println();
									fw1.close();
									System.out.println("updated the index page");
								}
								else
								{
									return false;
								}

								System.out.println("Post published");
							}
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
							return false;
						}
					}
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	private void printPost()
	{
		System.out.println("Title: "+ getTitle());
		System.out.println("Date: "+ getDate());
		System.out.println("Author: "+ getAuthor());
		System.out.println("Published: "+ getIsPublished());
	}
	private boolean getIsPublished() {
		return isPublished;
	}
	private void setIsPublished(boolean b) {
		isPublished = b;
	}
	private File getSource() {
		return source;
	}
	private File getDestination() {
		return destination;
	}
	private String getTitle() {
		return Title;
	}
	private void setTitle(String title) {
		Title = title;
	}
	private String getAuthor() {
		return Author;
	}
	private void setAuthor(String author) {
		Author = author;
	}
	private String getDate() {
		return Date;
	}
	private void setDate(String date) {
		Date = date;
	}


}
