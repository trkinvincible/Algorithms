#ifndef QT_NETWORK_H
#define QT_NETWORK_H

#include "command.h"

#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QNetworkSession>
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QtWidgets>
#include <QtCore>
#include <QByteArray>
#include <QDataStream>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0){}

    void doDownload(){

        manager = new QNetworkAccessManager(this);

        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));

        QUrl url("https://jsonmock.hackerrank.com/api/movies/search/");
        QNetworkRequest request;
        request.setUrl(url);

//        QSslConfiguration config = QSslConfiguration::defaultConfiguration();
//        config.setProtocol(QSsl::TlsV1SslV3);
//        request.setSslConfiguration(config);

        //request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

        //request.setRawHeader("User-Agent" , "Rk is reading" );
        //request.setRawHeader("Content-Type","application/json");
        manager->get(request);
    }

signals:

public slots:
    void replyFinished (QNetworkReply *reply){

        reply->ignoreSslErrors();

        if(reply->error())
        {
            qDebug() << "ERROR!";
            qDebug() << reply->errorString();
        }
        else
        {
            std::ofstream outfile("/media/trk/DATA/QtCreator-Projects/practice/test_c_plusplus/qt_network_test.txt");
            if(!outfile.is_open()){

                outfile.open("/media/trk/DATA/QtCreator-Projects/practice/test_c_plusplus/qt_network_test.txt",std::ofstream::out | std::ofstream::app);
            }
            std::cout << reply->bytesAvailable() << std::endl;
            std::cout << reply->readAll().toStdString() << std::endl;

            outfile << reply->readAll().toStdString() << std::endl;
            outfile.flush();
            outfile.close();

            if (reply->error() == QNetworkReply::NoError) {

                QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());

                QJsonObject jsonObj = jsonResponse.object();

                qDebug() << "total_pages:" << jsonObj["total_pages"].toInt();

                QJsonArray levelArray = jsonObj["data"].toArray();
                for (int levelIndex = 0; levelIndex < levelArray.size(); levelIndex++) {
                    QJsonObject levelObject = levelArray[levelIndex].toObject();
                    qDebug() << "Title: " << levelObject["Title"].toString();
                }

                delete reply;
            }
            else {
                //failure
                qDebug() << "Failure" <<reply->errorString();
                delete reply;
            }


            std::system("subl /home/thangrad/Documents/ML/practice/test_c_plusplus/qt_network_test.txt");
        }
    }

private:
   QNetworkAccessManager *manager;

};

class RkServer : public QObject
{
    Q_OBJECT

public:
    explicit RkServer(QWidget *parent = nullptr){

        tcpServer = new QTcpServer(this);
        if (!tcpServer->listen()) {

            std::cout << "Server isnt started to listen" << std::endl;
            return;
        }
        QString ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        std::cout << "Server is running at IP: " << ipAddress.toStdString() << " port: " << tcpServer->serverPort() << std::endl;

        connect(tcpServer, &QTcpServer::newConnection, this, &RkServer::SendGreetings);
    }

private slots:
    void SendGreetings(){

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << "va machi!!!\n\n";

        QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
        connect(clientConnection, &QAbstractSocket::disconnected,
                clientConnection, &QObject::deleteLater);

        clientConnection->write(block);
        clientConnection->flush();
        clientConnection->disconnectFromHost();
    }

private:
    QTcpServer *tcpServer = nullptr;
    QNetworkSession *networkSession = nullptr;
};

class qt_network: public Command{

    void execute(){

        int argc = 1;
        std::string s("test_c_plusplus");
        char * argv[] = {s.data()};
        
        QApplication app(argc,argv);

        Downloader d;
        d.doDownload();
        
        //RkServer server;

        app.exec();
    }
};

#endif // QT_NETWORK_H
