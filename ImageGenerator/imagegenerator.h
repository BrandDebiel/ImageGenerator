#ifndef IMAGEGENERATOR_H
#define IMAGEGENERATOR_H

#include <QCoreApplication>
#include <QImage>

class ImageGenerator
{
public:
    ImageGenerator();
    void makeImage(quint16 width, quint16 height, quint16 scanNumber);
    void createFolder();

private:
    QString m_filepath;
};

#endif // IMAGEGENERATOR_H
