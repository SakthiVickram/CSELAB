import  java.net.InetAddress;

class myip
{
public static void main(String args[]) throws Exception
{
InetAddress ip=InetAddress.getLocalHost();
System.out.println("IP Address:"+ip.getHostAddress());
System.out.println("Hostname:"+ip.getHostName());

}


}
