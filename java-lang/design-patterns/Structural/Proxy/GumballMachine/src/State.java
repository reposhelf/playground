import java.io.Serializable;

/**
 * Created by vova on 10/17/16.
 */
public interface State extends Serializable {
    public void insertQuarter();
    public void ejectQuarter();
    public void turnCrank();
    public void dispense();
    public String toString();
}
