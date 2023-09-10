#include <QTextStream>
#include <QString>
#include <QFile>
#include <QVector>
#include "Rectangle.h"

int main()
{
    QFile inputFile("rectangle.txt"); // read data
    QFile outputFile("rectangle_areas.txt"); // write data

    QTextStream out(&outputFile);
    QTextStream in(&inputFile);
    QTextStream cout(stdout);

    QVector<Rectangle*> myRectangles;

    double length;
    double width;

    inputFile.open(QIODevice::ReadOnly |
                   QIODevice::Text);

    while(!in.atEnd()){
        in>>length;
        in>>width;
        myRectangles.push_back(new Rectangle(length, width));
    }
    inputFile.close();

    // open output file
    outputFile.open(QIODevice::WriteOnly |
                    QIODevice::Text);

    for(int i = 0;i<myRectangles.size();i++){
        out<<myRectangles.at(i)->area()<<Qt::endl;
    }

    outputFile.flush();
    outputFile.close();

    // return the memory
    for(int i = 0;i<myRectangles.size();i++){
        delete myRectangles.at(i);
    }

    myRectangles.clear(); // empties the vector of garbage references

}


