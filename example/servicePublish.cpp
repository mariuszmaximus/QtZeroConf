#include <QCoreApplication>
#include "qzeroconf.h"
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  QZeroConf zeroConf;
  zeroConf.addServiceTxtRecord("name0", "value0");
  zeroConf.startServicePublish("Test", "_test._tcp", "local", 12345);  

  app.exec();
}