import java.io.*;
import java.util.*;
import java.net.*;
public class client
{
  public static void main(String args[]) throws UnknownHostException,IOException {
    Socket s=new Socket("172.17.13.42",8456);
    String st;
    Scanner sc=new Scanner(System.in);
    Scanner sc1=new Scanner(s.getInputStream());
    while(true){
    System.out.println("\nEnter the message :");
    st=sc.nextLine();
    System.out.println("client :"+" "+st);
    PrintStream p=new PrintStream(s.getOutputStream());
    p.println(st);
    String ano;
    ano=sc1.nextLine();
    System.out.print("server :"+" "+ano);
    if(ano.equals("bye")||st.equals("bye")) break;
   }
  }
}
