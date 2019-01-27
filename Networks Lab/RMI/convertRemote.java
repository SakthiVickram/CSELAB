import java.rmi.*;
import java.rmi.server.*;

public class convertRemote extends UnicastRemoteObject implements converter{

convertRemote()throws RemoteException{
super();
}

public long dectobin(int x){

int rem=0,ten=1;
long bno=0;
while(x!=0)
{
rem=x%2;
bno=bno+rem*ten;
ten=ten*10;
x/=2;
}
return bno;
}
}
