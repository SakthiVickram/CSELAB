import java.rmi.*;
import java.rmi.registry.*;

public class MyServer{

public static void main(String args[]){
try{

converter stub=new convertRemote();
Naming.rebind("rmi://localhost:5000/stark",stub);

}catch(Exception e){System.out.println(e);}
}

}
