
package javaapplication13;

import java.io.*;
import java.net.*;
import java.net.InetAddress; 
import java.net.DatagramPacket; 
import java.net.DatagramSocket; 


public class udpserver {
public static void main(String[] args) throws Exception {
       byte[] receive = new byte[65535];
       InetAddress ip = InetAddress.getLocalHost();
       DatagramSocket ds = new DatagramSocket(5645); 
     File file = new File("D:\\ttttttt.txt");
FileOutputStream fr=new FileOutputStream(file);
System.out.println(ds.isConnected());     
        DatagramPacket  DpReceive = new DatagramPacket(receive, receive.length); 
         ds.receive(DpReceive);
         System.out.println(ds.isConnected()); 
         System.out.println(new String(DpReceive.getData(),0,DpReceive.getLength()));
     fr.write(receive, 0, receive.length);
     
//System.out.println("hello"+receive.toString());

}
}