#include "morsetranslator.h"

#include <QDebug>
#include <QMap>

namespace {
QMap<QChar, QString> MORSE_TABLE = {
    {'a', ".- "}, {'m', "-- "}, {'y', "-.-- "}, {'.', ".-.-.- "},
    {'b', "-... "}, {'n', "-. "}, {'z', "--.. "}, {',', "--..-- "},
    {'c', "-.-. "}, {'o', "--- "}, {'0', "----- "}, {'?', "..--.. "},
    {'d', "-.. "}, {'q', ".--. "}, {'1', ".---- "}, {'!', "..--. "},
    {'e', ". "}, {'p', "--.- "}, {'2', "..--- "}, {':', "---... "},
    {'f', "..-. "}, {'r', ".-. "}, {'3', "...-- "}, {'"', ".-..-. "},
    {'g', "--. "}, {'s', "... "}, {'4', "....- "}, {'\'', ".----. "},
    {'h', ".... "}, {'t', "- "}, {'5', "..... "}, {'=', "-...- "},
    {'i', ".. "}, {'u', "..- "}, {'6', "-.... " }, {' ', " "},
    {'j', ".--- "}, {'v', "...- "}, {'7', "--... "},
    {'k', "-.- "}, {'w', ".-- "}, {'8', "---.. "},
    {'l', ".-.. "}, {'x', "-..- "}, {'9', "----. "}
};

QMap<QString, QChar> REVERSED_MORSE_TABLE = {
    {".-", 'a'}, {"--", 'm'}, {"-.--", 'y'}, {".-.-.-", '.'},
    {"-...", 'b'}, {"-.", 'n'}, {"--..", 'z'}, {"--..--", ','},
    {"-.-.", 'c'}, {"---", 'o'}, {"-----", '0'}, {"..--..", '?'},
    {"-..", 'd'}, {".--.", 'q'}, {".----", '1'}, {"..--.", '!'},
    {".", 'e'}, {"--.-", 'p'}, {"..---", '2'}, {"---...", ':'},
    {"..-.", 'f'}, {".-.", 'r'}, {"...--", '3'}, {".-..-.", '"'},
    {"--.", 'g'}, {"...", 's'}, {"....-", '4'}, {".----.", '\''},
    {"....", 'h'}, {"-", 't'}, {".....", '5'}, {"-...-", '='},
    {"..", 'i'}, {"..-", 'u'}, {"-....", '6'},
    {".---", 'j'}, {"...-", 'v'}, {"--...", '7'},
    {"-.-", 'k'}, {".--", 'w'}, {"---..", '8'},
    {".-..", 'l'}, {"-..-", 'x'}, {"----.", '9'}
};
}

MorseTranslator::MorseTranslator(QObject *parent)
    : AbstractTranslator(parent)
{
}

QString MorseTranslator::encode(const QString &text) const
{
    QString encodedText;
    for (const auto &c : text)
    {
        auto symbol = c.toLower();
        if (MORSE_TABLE.find(symbol) != MORSE_TABLE.end())
            encodedText += MORSE_TABLE[symbol];
    }
    return encodedText;
}

QString MorseTranslator::decode(const QString &text) const
{
    QString decodedText;
    QStringList splittedText = text.split(" ");

    for (const auto &combination : splittedText)
    {
        if (REVERSED_MORSE_TABLE.find(combination) != REVERSED_MORSE_TABLE.end())
            decodedText.append(REVERSED_MORSE_TABLE[combination]);

        if (combination.isEmpty())
            decodedText.append(' ');
    }
    return decodedText;
}
