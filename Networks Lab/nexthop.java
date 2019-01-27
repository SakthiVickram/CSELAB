import java.io.*;
import java.util.*;

public class nexthop
{
public static void main(String[] args)throws IOException
{
Process result=Runtime.getRuntime().exec("traceroute www.google.com");
BufferedReader output=new BufferedReader(new InputStreamReader(result.getInputStream()));
String line;
line=output.readLine();
for(int i=0;i<1;i++)
 {
line=output.readLine();
//System.out.println(line);
  }

Process result2=Runtime.getRuntime().exec("ip neigh");
BufferedReader output2=new BufferedReader(new InputStreamReader(result2.getInputStream()));

for(int i=0;i<1;i++)
{
line=output2.readLine();
//  System.out.println(line);
}
String tok[]=line.split(" ");
System.out.println("IP Address Next hop router:"+tok[0]);
System.out.println("MAC Address Next hop router:"+tok[4]);




}
}
