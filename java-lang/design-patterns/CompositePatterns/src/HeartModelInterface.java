/**
 * Created by vova on 12/29/16.
 */
public interface HeartModelInterface {
    void initialize();
    void on();
    void off();
    void setBPM(int bpm);
    int getHeartRate();
    void registerObserver(BeatObserver o);
    void removeObserver(BeatObserver o);
    void registerObserver(BPMObserver o);
    void removeObserver(BPMObserver o);
}
