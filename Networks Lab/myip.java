import  java.net.InetAddress;
import java.util.List;

class myip
{

    private static String dnsServer;
public static void main(String args[]) throws Exception
{
    List<String> nameservers = sun.net.dns.ResolverConfiguration.open ().nameservers();
    for( int i =1; i< nameservers.size() ; i++ )
{
 dnsServer =nameservers.get(i).toString();
 System.out.println("DNS Server:"+dnsServer);
}


}


}
