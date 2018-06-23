#include <QCoreApplication>
#include <QDebug>

#include "imagegenerator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "***     Yo dude, welcome!   ***";
    qInfo() << "*** Let's make some pictures***";

    quint16 imageWidth = 255;
    quint16 imageHeight = 255;
    quint16 scanNumber = 0;

    //Maak object imageGenerator
    ImageGenerator imageGenerator;

    //Genereer een afbeelding
    imageGenerator.makeImage(imageWidth,imageHeight, scanNumber);


    qInfo() << "*** Nice holiday pictures!! ***";


    return a.exec();
}
