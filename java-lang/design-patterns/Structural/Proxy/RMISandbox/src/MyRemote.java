import java.rmi.*;

/**
 * Created by vova on 10/5/16.
 */
public interface MyRemote extends Remote {
    public String sayHello() throws RemoteException;
}
