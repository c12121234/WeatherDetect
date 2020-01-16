#include "IArea.h"


IArea::IArea(QString strArea):
    m_strArea(strArea)
{
    vector<QString> vTemp;
    m_vLocation = vTemp;
    m_strAreaAPItext = "";
}

IArea::~IArea()
{

}

vector<QString> IArea::GetLocation()
{
    return m_vLocation;
}

QString IArea::GetAreaAPItext()
{
    return m_strAreaAPItext;
}
