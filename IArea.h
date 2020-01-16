#ifndef IAREA_H
#define IAREA_H
#include <QObject>
using std::vector;
class QString;

class IArea
{
public:
    IArea(QString strArea);
    virtual ~IArea();
    virtual vector<QString> GetLocation();
    QString GetAreaAPItext();
protected:
    vector<QString> m_vLocation;
    QString m_strArea;
    QString m_strAreaAPItext;
};
#endif // IAREA_H
