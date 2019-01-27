import java.util.*;
import java.io.*;
import java.net.*;
class server
{
  public static void main(String args[]) throws IOException
  {
    ServerSocket ss=new ServerSocket(1567);
    Socket s=ss.accept();
    Scanner sc=new Scanner(s.getInputStream());
    String g=sc.nextLine();
    PrintStream p=new PrintStream(s.getOutputStream());
    p.println(g);
    System.out.print("Message from client :");
    System.out.println(g);
  }
}
