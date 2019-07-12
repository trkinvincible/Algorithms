#ifndef QT_NETWORK_H
#define QT_NETWORK_H

#include "command.h"

#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
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


class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0){}

    void doDownload(){

        manager = new QNetworkAccessManager(this);

        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));

        QUrl url("https://jsonmock.hackerrank.com/api/movies/search/?Title=");
        QNetworkRequest request;
        request.setUrl(url);

        QSslConfiguration config = QSslConfiguration::defaultConfiguration();
        config.setProtocol(QSsl::TlsV1SslV3);
        request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

        request.setRawHeader("User-Agent" , "Rk is reading" );
        request.setRawHeader("Content-Type","application/json");
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
            std::ofstream outfile("/home/thangrad/Documents/ML/practice/test_c_plusplus/qt_network_test.txt");
            if(!outfile.is_open()){

                outfile.open("/home/thangrad/Documents/ML/practice/test_c_plusplus/qt_network_test.txt",std::ofstream::out | std::ofstream::app);
            }
            std::cout << reply->bytesAvailable() << std::endl;
            //outfile << reply->readAll().toStdString() << std::endl;
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


            std::system("gnome-open /home/thangrad/Documents/ML/practice/test_c_plusplus/qt_network_test.txt");
        }
    }

private:
   QNetworkAccessManager *manager;

};

class qt_network: public Command{

    void execute(){

        int argc = 1;
        char * argv[] = {"test_c_plusplus"};
        QApplication app(argc,argv);

        Downloader d;
        d.doDownload();

        app.exec();


    }
};

#endif // QT_NETWORK_H
