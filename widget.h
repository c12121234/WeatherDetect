#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <memory>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class WidgetImpl;
using std::shared_ptr;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();    
private:
    shared_ptr<WidgetImpl> m_spWidgetImpl;
};
#endif // WIDGET_H
