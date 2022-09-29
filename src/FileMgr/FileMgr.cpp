#include "FileMgr.h"

FileMgr::FileMgr(QObject *parent)
    : QObject{parent}
{}

QVariant FileMgr::run(QVariant file)
{
    QString fileStr = file.toString();
    qDebug("C++ get file:%s selected", fileStr.toStdString().data());

    return 0;
}
