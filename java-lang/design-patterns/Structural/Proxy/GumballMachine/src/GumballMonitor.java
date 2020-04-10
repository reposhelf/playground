import java.rmi.RemoteException;

/**
 * Created by vova on 10/19/16.
 */
public class GumballMonitor {
    GumballMachineRemote machine;

    public GumballMonitor(GumballMachineRemote machine) {
        this.machine = machine;
    }

    public void report() {
        try {
            System.out.println("Gumball Machile: " + machine.getLocation());
            System.out.println("Current inventory: " + machine.getCount() + " gumballs");
            System.out.println("Current state: " + machine.getState().toString());
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
