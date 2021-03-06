import java.io.*;
import java.net.*;
import java.util.*;

public class Server extends Thread {
private ServerSocket ss;
    public Server(int port) throws IOException
    {
       ss =new ServerSocket(port);
    }
    public void run() 
    {
        while(true)
        {
           try{
         System.out.println("Server is listening on port:"+ ss.getLocalPort());
        Socket ser= ss.accept();
Scanner ob =new Scanner(System.in);
         System.out.println("Client connected by host address:"+ser.getInetAddress().getHostAddress());
         OutputStream os=ser.getOutputStream();
         PrintWriter write=new PrintWriter(os,true);
         write.println("you are connected to the server");
         InputStream is=ser.getInputStream();
BufferedReader read=new BufferedReader(new InputStreamReader(is));
String line="hello";
while(!line.equals("bye"))
{
           line=read.readLine();
          System.out.println(line);
          
         
         write.println(ob.nextLine());
 }          
 System.out.println("loop ends");
           ser.close();
           }catch(IOException e){
                e.printStackTrace();
         
           }
        }
    }
   
    public static void main(String[] args) throws IOException {
       int port=Integer.parseInt(args[0]);
       Thread t=new Server(port);
       t.start();
    }
    
}
