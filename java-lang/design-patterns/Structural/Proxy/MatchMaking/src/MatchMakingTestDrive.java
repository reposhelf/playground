import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Proxy;

/**
 * Created by vova on 11/4/16.
 */
public class MatchMakingTestDrive {
    enum ProxyType {
        OwnerProxy,
        NotOwnerProxy
    }

    public static void main(String[] args) {
        MatchMakingTestDrive test = new MatchMakingTestDrive();
        test.drive();
    }

    public MatchMakingTestDrive() {
    }

    public void drive() {
        PersonBean joe = new PersonBeanImpl();
        joe.setName("Joe Javabean");
        joe.setGender("Male");

        PersonBean ownerProxy = getProxy(joe, ProxyType.OwnerProxy);
        System.out.println("Name is " + ownerProxy.getName());
        ownerProxy.setInterests("Bowling, Go");
        System.out.println("Interests set from owner proxy");
        try {
            ownerProxy.setHotOrNotRting(10);
        } catch (Exception e) {
            System.out.print("Can't set rating from owner proxy");
        }
        System.out.print("Rating is " + ownerProxy.getHotOrNotRating());
    }

    public InvocationHandler createInvocationHandler(PersonBean person, ProxyType type) {
        switch (type) {
            case OwnerProxy:
                return new OwnerInvocationHandler(person);
            case NotOwnerProxy:
                return new NotOwnerInvocationHandler(person);
            default:
                break;
        }
        return null;
    }

    public PersonBean getProxy(PersonBean person, ProxyType type) {
        return (PersonBean) Proxy.newProxyInstance(
                person.getClass().getClassLoader(),
                person.getClass().getInterfaces(),
                createInvocationHandler(person, type)
        );
    }
}
