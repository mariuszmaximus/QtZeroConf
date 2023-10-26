#include <QCoreApplication>
#include "qzeroconf.h"

#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

    QZeroConf zeroConf;
    zeroConf.startBrowser("_test._tcp");
    // zeroConf.startBrowser("_http._tcp");

    QObject::connect(&zeroConf, &QZeroConf::serviceAdded, &app, [](QZeroConfService zcs){
        qDebug() << "Added service: " << zcs;
        qDebug() << "Name:" << zcs->name();
        qDebug() << "Type:" << zcs->type();
        qDebug() << "Domain:" << zcs->domain();
        qDebug() << "Host:" << zcs->host();
        qDebug() << "IP:"<<zcs->ip().toString();
        qDebug() << "TXT:"<<zcs->txt();
    } );

    app.exec();
}