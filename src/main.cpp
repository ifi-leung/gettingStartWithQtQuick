#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "./FileMgr/FileMgr.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/src/QML/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        qInfo("%s start\n", QCoreApplication::applicationName().toLatin1().data());

        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    FileMgr fileMgr;
    engine.rootContext()->setContextProperty(QStringLiteral("fileMgrInstance"), &fileMgr);
    engine.load(url);

    return app.exec();
}
