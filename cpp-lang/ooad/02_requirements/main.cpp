#include "dogdoor.h"
#include "remote.h"
#include "barkrecognizer.h"
#include "bark.h"

#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

int main()
{
    DogDoor door;
//    Remote remote(&door);
    BarkRecognizer recognizer(&door);
    recognizer.addBark(Bark("rowfl"));
    recognizer.addBark(Bark("rooowfl"));
    recognizer.addBark(Bark("rawfl"));
    recognizer.addBark(Bark("woof"));

    cout << "Bruce starts barking." << endl;
    recognizer.recognize(Bark("rowfl"));

    cout << "\nBruce has gone outside..." << endl;

    std::this_thread::sleep_for(std::chrono::seconds(10));

    cout << "\nBruse's all done..." << endl;
    cout << "...but he's stuck outside!" << endl;

    Bark smallDogBark("yip");
    cout << "Bitsie starts barking." << endl;
    recognizer.recognize(smallDogBark);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    cout << "Bruce starts barking." << endl;
    recognizer.recognize(Bark("rooowfl"));

    cout << "\nBruce's back inside...." << endl;

    std::getchar();

    return 0;
}
