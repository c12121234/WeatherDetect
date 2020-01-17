#include "judgepic.h"
#include <QObject>


std::pair<int, int> JudgePic::JudgePicPos(const QString strWeather)
{
    //get pic coordinate point.
    int posX = 73,posY = 113;
    if(strWeather == "晴時多雲")
    {
        posX += (187+162)*2;
    }
    else if(strWeather == "晴")
    {
        posX += (187+162);
    }
    else if(strWeather == "多雲")
    {
        //origin point
    }
    else if(strWeather == "短暫雨")
    {
        posY += (187+125);
    }
    else if(strWeather == "陰短暫雨")
    {
        posX += (187+162)*2;
        posY += (187+125)*2;
    }
    else if(strWeather == "陰天")
    {
        posX += (187+162);
        posY += (187+125)*2;
    }
    return std::make_pair(posX,posY);
}

JudgePic::JudgePic()
{

}
