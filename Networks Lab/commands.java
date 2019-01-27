
import java.io.*;
import java.util.*;

public class commands
{
public static void main(String[] args)throws IOException
{
Process result=Runtime.getRuntime().exec("ping www.google.com");
StringBuffer cmd=new StringBuffer("echo ");
BufferedReader output=new BufferedReader(new InputStreamReader(result.getInputStream()));
String line,str;
int i=0;
Scanner ob=new Scanner(System.in);
System.out.println("pinging google");
while((line=output.readLine())!=null)
{
line=output.readLine();
System.out.println(line);
if(i>5)
break;
i++;
}

System.out.println("enter the string to echo");

cmd.append(ob.nextLine());
str=cmd.toString();
System.out.println(str);
Process result2=Runtime.getRuntime().exec(str);
BufferedReader output2=new BufferedReader(new InputStreamReader(result2.getInputStream()));

line=output2.readLine();
 System.out.println(line);




}
}
