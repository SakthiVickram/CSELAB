
package port;
import java.io.IOException;
import java.net.*;

public class Port {

    
    public static void main(String[] args) throws IOException {
       for(int i=5000 ;i<=65535;i++)
       {
           System.out.println(" ports"+i);
           try {
               Socket s = new Socket(); 
               s.connect(new InetSocketAddress("localhost",i),1000);
           
           System.out.println("open ports"+i);
           }
           catch(Exception e)
           {}
       }
    }
    
}
