/**
 * Created by vova on 9/30/16.
 */
public class WinnerState implements State {
    GumballMachine gumballMachine;

    public WinnerState(GumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("You can't insert a quarter, the machine is sold out");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("You can't eject, you haven't inserted a quarter yet");
    }

    @Override
    public void turnCrank() {
        System.out.println("Turning twice doesn't get you another gumballs");
    }

    @Override
    public void dispense() {
        System.out.println("YOU'RE A WINNER! You get two gumballs for your quarter");
        System.out.println("A gumball comes rolling out the slot");
        gumballMachine.releaseBall();
        if (gumballMachine.count == 0) {
            gumballMachine.setState(gumballMachine.getSoldOutState());
        } else {
            System.out.println("A gumball comes rolling out the slot");
            gumballMachine.releaseBall();
            if (gumballMachine.count > 0) {
                gumballMachine.setState(gumballMachine.getNoQuarterState());
            } else {
                System.out.println("Oops, out of gumballs");
                gumballMachine.setState(gumballMachine.getSoldOutState());
            }
        }
    }
}
