#ifndef JUGEPIC_H
#define JUGEPIC_H

#include <utility>
class QString;
class JudgePic
{
public:
    static std::pair<int,int> JudgePicPos(const QString strWeather);
private:
    JudgePic();
};

#endif // JUGEPIC_H
