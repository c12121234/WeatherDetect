#ifndef AREAFACTORY_H
#define AREAFACTORY_H

#include <QObject>
#include <map>
#include <memory>
using std::shared_ptr;
class IArea;
class AreaFactory
{
public:    
    static shared_ptr<IArea> CreateArea(const QString strArea);
private:
    AreaFactory();
    AreaFactory(const AreaFactory& cptr) = delete;
    AreaFactory& operator=(const AreaFactory& asop) = delete;

};

#endif // AREAFACTORY_H
