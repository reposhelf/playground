import java.rmi.Naming;

/**
 * Created by vova on 10/19/16.
 */
public class GumballMonitorTestDrive {
    public static void main(String[] args) {
        String[] locations = {
                "rmi://127.0.0.1/santafe.mightgumball.com/gumballmachine",
                "rmi://127.0.0.1/boulder.mightgumball.com/gumballmachine",
                "rmi://127.0.0.1/seatle.mightgumball.com/gumballmachine"
        };

        GumballMonitor[] monitors = new GumballMonitor[locations.length];

        for (int i = 0; i < locations.length; ++i) {
            try {
                GumballMachineRemote machine = (GumballMachineRemote) Naming.lookup(locations[i]);
                monitors[i] = new GumballMonitor(machine);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        for (int i = 0; i < monitors.length; ++i) {
            monitors[i].report();
            System.out.println();
        }
    }
}
