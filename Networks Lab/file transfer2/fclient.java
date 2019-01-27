/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication12;

import java.io.*;
import java.net.*;
public class fclient{
public static void main(String[] argv) throws Exception {

Socket sr=new Socket("localhost",5644);
InputStream is=sr.getInputStream();
int len=is.read();

File file = new File("D:\\ttttttt.txt");
FileOutputStream fr=new FileOutputStream(file);
System.out.println(len);
byte []b=new byte[len];
is.read(b,0,b.length);
fr.write(b, 0, b.length);
}
}