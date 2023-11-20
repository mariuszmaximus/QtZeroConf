#include "widget.h"
#include "./ui_widget.h"
#include "qzeroconf.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


	ui->plainTextEdit->appendPlainText("start APP");
	ui->plainTextEdit->appendPlainText(".");


	auto *zeroConf = new QZeroConf(this);
	zeroConf->startBrowser("_test._tcp");

	QObject::connect(zeroConf, &QZeroConf::serviceAdded, this, [this](QZeroConfService zcs){
		qDebug() << "Added service: " << zcs;
		qDebug() << "Name:" << zcs->name(); ui->plainTextEdit->appendPlainText(zcs->name());
		qDebug() << "Type:" << zcs->type();
		qDebug() << "Domain:" << zcs->domain();
		qDebug() << "Host:" << zcs->host();
		qDebug() << "IP:"<<zcs->ip().toString();
		qDebug() << "TXT:"<<zcs->txt();
	} );
}

Widget::~Widget()
{
    delete ui;
}

