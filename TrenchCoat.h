#ifndef TRENCHCOAT_H
#define TRENCHCOAT_H
#include <QString>
#include <QVariant>

class TrenchCoat{
public:
    TrenchCoat() = default;
    TrenchCoat(int _i):i{_i}{};
    QString toString() const
      {
        return first + second + std::to_string(i).c_str();
      }
    QString first{"penis"};
    QString second{"cock"};
    int i{0};
};
Q_DECLARE_METATYPE(TrenchCoat);


#endif // TRENCHCOAT_H
