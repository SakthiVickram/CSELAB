import java.io.*;
import java.util.*;
import java.net.*;
class client
{
  public static void main(String args[]) throws UnknownHostException,IOException {
    System.out.println("connecting......");
    Socket s=new Socket("127.0.0.1",1567);
    String st;
    Scanner sc=new Scanner(System.in);
    Scanner sc1=new Scanner(s.getInputStream());
    System.out.println("Enter a string :");
    st=sc.nextLine();
    PrintStream p=new PrintStream(s.getOutputStream());
    p.println(st);
    String ano;
    ano=sc1.nextLine();
    System.out.print("Echoed from server :");
    System.out.println(ano);
  }
}
