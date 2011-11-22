#include "mainwindow.h"
#include<QFileDialog>
mainwindow::mainwindow(){
    hd = new helpdialog;
    m=new mediaobject;
    setupUi(this);
    setWindowTitle("Music Player");

    show();
    // Signal and slots for help -> AboutUs
    QObject::connect(actionAbout, SIGNAL(triggered()), this, SLOT(helpShow()));
    QObject::connect(actionExit,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(actionAdd_Files,SIGNAL(triggered()),this,SLOT(addFiles()));
    QObject::connect(buttonPause,SIGNAL(clicked()),this,SLOT(pauseFile()));
    QObject::connect(buttonPlay,SIGNAL(clicked()),this,SLOT(playCurrent()));
    QObject::connect(buttonStop,SIGNAL(clicked()),this,SLOT(stopFile()));


}

void mainwindow::helpShow(){
    hd->show();
}

void mainwindow::addFiles()
{
    QString filename=QFileDialog::getOpenFileName();
    currentFileName=filename;
    m=new mediaobject;
    m->enqueue(filename);
    QTableWidgetItem *newItem=new QTableWidgetItem(filename,0);
    tableSongs->setItem(1,1,newItem);
}

void mainwindow::playCurrent()
{
    //if(!currentFileName.isEmpty())
        m->playFile(currentFileName);
}

void mainwindow::pauseFile()
{
    m->pauseFile();
}

void mainwindow::stopFile()
{
    m->stop();
}

