/*
* Copyleft (l) Useless NV. All rights dispensed.
* Free and for useless use only. The contents of this document consitutes shared
* information of Useless Group of companies. If you use this in a useful way, you dissapoint me.
* Author: hajayedamir@gmail.com
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include <UselessStats.h>
#include <StartupHandler.h>
#include <GlobalConstants.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    StartupHandler startup;
    if (!startup.setupApplication())
    {
        return -1;
    }

    UselessStats stats(startup.getUselessStatsPath());

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/UselessApps/resources/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("uselessStats", &stats);
    engine.load(url);

    return app.exec();
}
