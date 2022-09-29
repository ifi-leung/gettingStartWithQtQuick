#ifndef FILEMGR_H
#define FILEMGR_H

#include <QObject>
#include <QVariant>

class FileMgr : public QObject
{
    Q_OBJECT
public:
    explicit FileMgr(QObject *parent = nullptr);

    Q_INVOKABLE QVariant run(QVariant file);
};

#endif // FILEMGR_H
