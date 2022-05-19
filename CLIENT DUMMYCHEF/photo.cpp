#include "photo.h"
#include <QStringList>
#include <QString>
#include <QImage>


Photo::Photo()
{


}

Photo::Photo(QString nume, unsigned int size)
{
    this->size=size;
    this->name=nume;
}

QImage Photo::createPath()
{
    QImage img;
    img.loadFromData(this->buffer.toUtf8());

    return img;
}

void Photo::addData(QByteArray data)
{
    // 18/nume poza/numar octeti/octeti/18

    QStringList tok = QString(data).split('/');
    if(tok.size() > 1)
    {
        this->name = tok[1];
        this->size = tok[2].toInt();
        this->buffer += tok[3];
    }
    else
    {
        if(tok.size() == 2)
        {
            this->buffer += QString(tok[1]);
        }
        else
        {
            this->buffer += QString(tok[0]);
        }
    }
    if(tok[tok.size()-1] == "18")
    {
        this->done = true;
    }
}

bool Photo::isDone()
{
    return this->done;
}

