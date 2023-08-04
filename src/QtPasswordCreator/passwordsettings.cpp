#include "passwordsettings.h"
#include <QRandomGenerator>

PasswordSettings::PasswordSettings(bool _useSpecialSigns, bool _useNumbers, uint8_t _length)
{
    useSpecialSigns = _useSpecialSigns;
    useNumbers = _useNumbers;
    pwLength = _length;
}

QString PasswordSettings::Generate()
{
    QString result;

    for (int i = 0; i < pwLength; ++i) {
        if (useSpecialSigns && i % 3 == 0) {
            // Add a random special character if useSpecialSigns is true
            int randomIndex = QRandomGenerator::global()->bounded(possibleSpecialSigns.length());
            result.append(possibleSpecialSigns[randomIndex]);
        } else if (useNumbers && i % 2 == 0) {
            // Add a random number if useNumbers is true
            int randomNumber = QRandomGenerator::global()->bounded(10); // Numbers 0 to 9
            result.append(QString::number(randomNumber));
        } else {
            // Add a random letter
            int randomIndex = QRandomGenerator::global()->bounded(possibleCharacters.length());
            result.append(possibleCharacters[randomIndex]);
        }
    }

    return result;
}
