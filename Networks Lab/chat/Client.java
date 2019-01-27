import java.net.*;
import java.io.*;
import java.util.*;

public class Client {

    public static void main(String[] args) {
        if (args.length < 2) return;

        String hostname = args[0];
        int port = Integer.parseInt(args[1]);

        try (Socket socket = new Socket(hostname, port)) {

            InputStream input = socket.getInputStream();
            OutputStream os=socket.getOutputStream();
		Scanner ob =new Scanner(System.in);
 BufferedReader reader = new BufferedReader(new InputStreamReader(input));
String line="hello";
PrintWriter write=new PrintWriter(os,true);
		while(!line.equals("bye"))
{
           line=reader.readLine();
          System.out.println(line);
          
         
         write.println(ob.nextLine());
 }          
    
     System.out.println("loop ends");
} catch (UnknownHostException ex) {

            System.out.println("Server not found: " + ex.getMessage());

        } catch (IOException ex) {

            System.out.println("I/O error: " + ex.getMessage());
        }
    }
}

