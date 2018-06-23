#include "imagegenerator.h"
#include <QImage>
#include <QDir>
#include <QDebug>

ImageGenerator::ImageGenerator()
{

}

void ImageGenerator::makeImage(quint16 width, quint16 height, quint16 scanNumber) //Deze functie uitbreiden met je scandata
{
    QImage image(width,height, QImage::Format_Grayscale8);    //Maak grijswaarden afbeelding met formaat width x height
    image.fill(qRgb(0,0,0));                                  //Initaliseer de afbeelding met RGB 0,0,0 (zwart)

    //Verwerk de data in de afbeelding
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            //scanData in de afbeelding verwerken
            image.setPixel( x, y, qRgb(x, x, x));   //Hier ga je alle X en Y coordinaten af van de afbeelding
                                                    //qRgb(x, x, x) op de plaatse van de X doe je de scandata
                                                    //voor die betreffende pixel, op alle x dezelfde data en
                                                    //maximaal waarde 255.
        }
    }

    createFolder(); //Maak map aan op de sjizzle in op te slaan

    //Sla de afbeelding op in de map 'm_filePath', de naam van de afbeelding
    //is ÍMAGE<scanNumber>.png
    //
    //'arg(scanNumber,3,10, QChar('0')' zorgt net als in creatFolder() voor de juiste opmaak
    //dus alle namen worden IMAGE000, IMAGE001 ... IMAGE025, etc.

    image.save(m_filepath + QString("IMAGE%1.png").arg(scanNumber,3,10, QChar('0')));

}

void ImageGenerator::createFolder()
{

    for(int i = 0; i < 1000; i++)
    {
        //Maak directory in de werkfolder(standaard waar Qt je build maakt > zie project settings)
        //in de folder gaan we een folder IMG000 maken, iedere opvolgende folder krijgt een opvolgend
        //nummer dus IMG001, IMG002
        m_filepath = QCoreApplication::applicationDirPath()
                            + QString("/IMG%1/")
                                .arg(i,3,10, QChar('0'));

        //Kijk of de folder al bestaat, anders tellen we een op en maken we de folder zodra we een
        //naam hebben die nog niet bestaat tot maximaal naam IMG999
        if(!QDir(m_filepath).exists() && (i < 999))
        {
            QDir().mkdir(m_filepath);
            qInfo () << "ImageGenerator" << "created: " << m_filepath;
            break;
        }
        if(i > 999)
        {
            qWarning() << "all foldernames occupied";
            break;
        }
    }

}
