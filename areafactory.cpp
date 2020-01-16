#include "areafactory.h"
#include "IArea.h"
#include "carea.h"
#include <memory>
#include <utility>
#include <QTextCodec>
#include <QString>

shared_ptr<IArea> AreaFactory::CreateArea(const QString strArea)
{
    if(strArea == "宜蘭縣")
        return std::make_shared<YilanCountyArea>("宜蘭縣");
    else if(strArea == "桃園市")
        return std::make_shared<TaoyuanCity>("桃園市");
    else if(strArea == "新竹縣")
        return std::make_shared<HsinchuCounty>("新竹縣");
    else if(strArea == "苗栗縣")
        return std::make_shared<MiaoliCounty>("苗栗縣");
    else if(strArea == "彰化縣")
        return std::make_shared<ChanghuaCounty>("彰化縣");
    else if(strArea == "南投縣")
        return std::make_shared<NantouCounty>("南投縣");
    else if(strArea == "雲林縣")
        return std::make_shared<YunlinCounty>("雲林縣");
    else if(strArea == "嘉義縣")
        return std::make_shared<ChiayiCounty>("嘉義縣");
    else if(strArea == "屏東縣")
        return std::make_shared<PingtungCounty>("屏東縣");
    else if(strArea == "臺東縣")
        return std::make_shared<TaitungCounty>("臺東縣");
    else if(strArea == "花蓮縣")
        return std::make_shared<HualienCounty>("花蓮縣");
    else if(strArea == "澎湖縣")
        return std::make_shared<PenghuCounty>("澎湖縣");
    else if(strArea == "基隆市")
        return std::make_shared<KeelungCity>("基隆市");
    else if(strArea == "新竹市")
        return std::make_shared<HsinchuCity>("新竹市");
    else if(strArea == "嘉義市")
        return std::make_shared<ChiayiCity>("嘉義市");
    else if(strArea == "臺北市")
        return std::make_shared<TaipeiCity>("臺北市");
    else if(strArea == "高雄市")
        return std::make_shared<Kaohsiung>("高雄市");
    else if(strArea == "新北市")
        return std::make_shared<NewTaipeiCity>("新北市");
    else if(strArea == "臺中市")
        return std::make_shared<Taichung>("臺中市");
    else if(strArea == "臺南市")
        return std::make_shared<TainanCity>("臺南市");
    else if(strArea == "連江縣")
        return std::make_shared<LianjiangCounty>("連江縣");
    else if(strArea == "金門縣")
        return std::make_shared<KinmenCounty>("金門縣");
    return nullptr;
}

AreaFactory::AreaFactory()
{

}
