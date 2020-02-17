#include "widget.h"
#include "widgetimpl.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_spWidgetImpl(std::make_shared<WidgetImpl>(this))
{

}

Widget::~Widget()
{

}

