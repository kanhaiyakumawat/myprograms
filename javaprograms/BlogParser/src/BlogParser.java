import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * 
 */
//import org.markdown4j.Markdown4jProcessor;
/**
 * @author kkumawat
 *
 */
public class BlogParser {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("starting the blog parser");
		final File source = new File("source");
		if(!source.exists())
		{
		System.out.println("There is no source folder provided");
		return;
		}
		final File destination = new File("destination");
		if(!destination.exists())
		{
		destination.mkdir();
		}
		parseBlog(source, destination);

	}
	public static void parseBlog(final File source, final File destination)
	{
		//search all the files in source folder and pass parse each file
		for(final File fileEntry : source.listFiles())
		{
			if(fileEntry.isFile())
			{
				System.out.println(fileEntry.getName());
				ParsePost parsepost = new ParsePost(fileEntry, destination);
				try {
					if(!parsepost.parse())
					{
						System.out.println("could not parse the post");
						return;
					}
					if(!parsepost.publish())
					{
						System.out.println("could not publish the post");
					}
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}

}
