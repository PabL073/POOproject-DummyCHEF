#ifndef PHOTO_H
#define PHOTO_H
#include<QString>

class QImage;

class Photo
{
public:
    Photo();
    Photo(QString nume, unsigned int size);

private:
    QString name;
    unsigned int size;
    QString buffer;
    QString path;
    bool done = false;

 public:
    QImage createPath();
    void addData(QByteArray data);
    bool isDone();
};

#endif // PHOTO_H
