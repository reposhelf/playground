import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Enumeration;
import java.util.Hashtable;

/**
 * Created by vova on 10/26/16.
 */
public class ImageProxyTestDrive {
    ImageComponent imageComponent;
    JFrame frame = new JFrame("CD Cover Viewer");
    JMenuBar menuBar;
    JMenu menu;
    Hashtable cds = new Hashtable();

    public static void main(String[] args) throws Exception {
        ImageProxyTestDrive testDrive = new ImageProxyTestDrive();
    }

    public ImageProxyTestDrive() throws Exception {
        cds.put("The Wonder of You: Elvis Presley with The Royal Philharmonic Orchestra",
                "https://images-na.ssl-images-amazon.com/images/I/71%2BNjLauEbL._SX522_.jpg");
        cds.put("Guardians of the Galaxy: Awesome Mix Vol.1",
                "https://images-na.ssl-images-amazon.com/images/I/81pKJyoiWFL._SX522_.jpg");
        cds.put("Adele: 25 CD",
                "https://images-na.ssl-images-amazon.com/images/I/81q0mwIoc0L._SX522_.jpg");
        cds.put("Metallica: Hardwired...To Self-Destruct (Limited Deluxe Edition)",
                "https://images-na.ssl-images-amazon.com/images/I/51opoXRMkAL.jpg");
        cds.put("Lady Gaga: Joanne",
                "https://images-na.ssl-images-amazon.com/images/I/71IteMIfi2L._SX522_.jpg");
        cds.put("Kenny Chesney: Cosmic Hallelujah",
                "https://images-na.ssl-images-amazon.com/images/I/A16vgsw6dGL._SX522_.jpg");
        cds.put("Pentatonix: That's Christmas To Me",
                "https://images-na.ssl-images-amazon.com/images/I/811PftAJRoL._SX522_.jpg");
        cds.put("Norah Jones: Day Breaks",
                "https://images-na.ssl-images-amazon.com/images/I/715CNF-LxIL._SX522_.jpg");

        URL initialURL = new URL((String)cds.get("Adele: 25 CD"));
        menuBar = new JMenuBar();
        menu = new JMenu("Favorite CDs");
        menuBar.add(menu);
        frame.setJMenuBar(menuBar);

        for (Enumeration e = cds.keys(); e.hasMoreElements();) {
            String name = (String)e.nextElement();
            JMenuItem menuItem = new JMenuItem(name);
            menu.add(menuItem);
            menuItem.addActionListener(event -> {
                imageComponent.setIcon(new ImageProxy(getCDURL(event.getActionCommand())));
                frame.repaint();
            });
        }

        Icon icon = new ImageProxy(initialURL);
        imageComponent = new ImageComponent(icon);
        frame.getContentPane().add(imageComponent);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);
        frame.setVisible(true);
    }

    URL getCDURL(String name) {
        try {
            return new URL((String)cds.get(name));
        } catch (MalformedURLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
