import java.io.*;
import java.util.*;

public class dns
{
public static void main(String[] args)throws IOException
{
Process result=Runtime.getRuntime().exec("nslookup localhost");
BufferedReader output=new BufferedReader(new InputStreamReader(result.getInputStream()));
String line;
line=output.readLine();
System.out.println("DNS IP address:");
System.out.println(line); 
Process result2=Runtime.getRuntime().exec("dnsdomainname");
BufferedReader output2=new BufferedReader(new InputStreamReader(result2.getInputStream()));
line=output2.readLine();
System.out.println("DNS hostname:"+line);

}
}
