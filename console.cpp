#include "console.h"
#include <QtWidgets>
Console::Console(QWidget *parent) : QTextEdit(parent)
{
    QPalette pal;
    pal.setColor(QPalette::Base, Qt::black);
    pal.setColor(QPalette::Text, Qt::white);
    setPalette(pal);

}
