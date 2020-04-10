import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

/**
 * Created by vova on 10/17/16.
 */
public class GumballMachine extends UnicastRemoteObject implements GumballMachineRemote {
    State soldOutState;
    State noQuarterState;
    State hasQuarterState;
    State soldState;
    State winnerState;

    State state = soldOutState;
    int count = 0;
    String location;

    public GumballMachine(String location, int count) throws RemoteException{
        soldOutState = new SoldOutState(this);
        noQuarterState = new NoQuarterState(this);
        hasQuarterState = new HasQuarterState(this);
        soldState = new SoldState(this);
        winnerState = new WinnerState(this);

        this.count = count;
        if (count > 0) {
            state = noQuarterState;
        }

        this.location = location;
    }

    public int getCount() {
        return count;
    }

    public String getLocation() {
        return location;
    }

    public State getState() {
        return state;
    }

    public void insertQuarter() {
        state.insertQuarter();
    }

    public void ejectQuarter() {
        state.ejectQuarter();
    }

    public void turnCrank() {
        state.turnCrank();
        state.dispense();
    }

    public void releaseBall() {
        if (count != 0) --count;
    }

    public void setState(State state) {
        this.state = state;
    }

    public State getSoldOutState() {
        return soldOutState;
    }

    public State getNoQuarterState() {
        return noQuarterState;
    }

    public State getHasQuarterState() {
        return hasQuarterState;
    }

    public State getSoldState() {
        return soldState;
    }

    public State getWinnerState() {
        return winnerState;
    }

    public void refill(int count) {
        this.count = count;
        setState(noQuarterState);
        System.out.println("Gumball Machine is refilled");
    }

    @Override
    public String toString() {
        String stateToString = (count <= 0) ? "sold out" : "waiting for quarter";

        return "Mighty Gumball, Inc\n" +
                "Java-enabled Standing Gumball Model #2004\n" +
                "Inventory: " + count + " gumballs\n" +
                "Machine is " + stateToString + "\n";
    }
}
