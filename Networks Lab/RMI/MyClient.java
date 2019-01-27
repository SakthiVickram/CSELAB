import java.rmi.*;

public class MyClient{

public static void main(String args[]){

String a=args[0];
int b=Integer.parseInt(a);
try{

converter stub=(converter)Naming.lookup("rmi://localhost:5000/stark");
System.out.println(stub.dectobin(b));

}catch(Exception e){System.out.println(e);}
}

}
