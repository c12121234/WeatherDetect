#ifndef CAREA_H
#define CAREA_H
#include "IArea.h"
#include <QObject>
#include <memory>
using std::vector;
using std::shared_ptr;
class YilanCountyArea :public IArea
{
public:
    YilanCountyArea(QString strArea);
};

class TaoyuanCity :public IArea
{
public:
    TaoyuanCity(QString strArea);
};

class HsinchuCounty :public IArea
{
public:
    HsinchuCounty(QString strArea);
};

class MiaoliCounty :public IArea
{
public:
    MiaoliCounty(QString strArea);
};

class ChanghuaCounty :public IArea
{
public:
    ChanghuaCounty(QString strArea);
};

class NantouCounty :public IArea
{
public:
    NantouCounty(QString strArea);
};

class YunlinCounty :public IArea
{
public:
    YunlinCounty(QString strArea);
};

class ChiayiCounty :public IArea
{
public:
    ChiayiCounty(QString strArea);
};

class PingtungCounty :public IArea
{
public:
    PingtungCounty(QString strArea);
};

class TaitungCounty :public IArea
{
public:
    TaitungCounty(QString strArea);
};

class HualienCounty :public IArea
{
public:
    HualienCounty(QString strArea);
};

class PenghuCounty :public IArea
{
public:
    PenghuCounty(QString strArea);
};

class KeelungCity :public IArea
{
public:
    KeelungCity(QString strArea);
};

class HsinchuCity :public IArea
{
public:
    HsinchuCity(QString strArea);
};

class ChiayiCity :public IArea
{
public:
    ChiayiCity(QString strArea);
};

class TaipeiCity :public IArea
{
public:
    TaipeiCity(QString strArea);
};

class Kaohsiung :public IArea
{
public:
    Kaohsiung(QString strArea);
};

class NewTaipeiCity :public IArea
{
public:
    NewTaipeiCity(QString strArea);
};

class Taichung :public IArea
{
public:
    Taichung(QString strArea);
};

class TainanCity :public IArea
{
public:
    TainanCity(QString strArea);
};

class LianjiangCounty :public IArea
{
public:
    LianjiangCounty(QString strArea);
};

class KinmenCounty :public IArea
{
public:
    KinmenCounty(QString strArea);
};
#endif // CAREA_H
