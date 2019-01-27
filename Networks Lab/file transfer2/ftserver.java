
package javaapplication12;

import java.io.*;
import java.net.*;
public class ftserver {
public static void main(String[] args) throws Exception {
ServerSocket s=new ServerSocket(5644);
Socket sr=s.accept();
File file=new File("D:\\serverfile.txt");
FileInputStream fr=new FileInputStream(file);
/* include your file name which you want to move*/
byte b[]=new byte[(int)file.length()];
fr.read(b, 0, b.length);
OutputStream os=sr.getOutputStream();
OutputStream os2=sr.getOutputStream();
//DataOutputStream OutToClient = new DataOutputStream(sr.getOutputStream());
os2.write(b.length);
System.out.println("len"+b.length);
os.write(b, 0, b.length);

}
}