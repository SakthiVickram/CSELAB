
import java.io.*;
import java.net.DatagramPacket; 
import java.net.DatagramSocket; 
import java.net.InetAddress; 

public class udpclient {
    public static void main(String[] args) throws Exception {
  DatagramSocket ds = new DatagramSocket(); 
 InetAddress ip = InetAddress.getLocalHost(); 
File file=new File("D:\\clientfile.txt");
FileInputStream fr=new FileInputStream(file);
/* include your file name which you want to move*/
byte b[]=new byte[(int)file.length()];
fr.read(b, 0, b.length);
System.out.println(ds.isConnected());
while(true)
{
DatagramPacket DpSend = new DatagramPacket(b, b.length, ip, 5645); 

ds.send(DpSend); 

}
//System.out.println((DpSend.getData()).toString());
//System.out.println("len"+b.length);
    }
}
