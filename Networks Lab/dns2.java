import java.io.*;
import java.util.*;

public class dns2
{
public static void main(String[] args)throws IOException
{
String a= args[0];
String b= args[1];
StringBuffer cmd = new StringBuffer("nslookup ");
cmd.append(a+" ");
cmd.append(b);
System.out.println(cmd);
String cmd2=cmd.toString();
Process result=Runtime.getRuntime().exec(cmd2);
BufferedReader output=new BufferedReader(new InputStreamReader(result.getInputStream()));
String line;
while((line=output.readLine())!=null)
{ 
 line=output.readLine();
 System.out.println(line); 
}
 
}
}
