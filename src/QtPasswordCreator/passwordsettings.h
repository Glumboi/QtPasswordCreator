#ifndef PASSWORDSETTINGS_H
#define PASSWORDSETTINGS_H

#include <QString>
#include <cstdint>

class PasswordSettings
{
public:
    bool useNumbers, useSpecialSigns;
    uint8_t pwLength;
    PasswordSettings(bool _useSpecialSigns, bool _useNumbers, uint8_t _length);
    QString Generate();
private:
    const QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const QString possibleNumbers = "0123456789";
    const QString possibleSpecialSigns = "!@#$%^&*()_-+=<>?";
};

#endif // PASSWORDSETTINGS_H
