#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "helpui.h"
#include <QMainWindow>
#include "mediafile.h"

class mainwindow: public QMainWindow, Ui::MainWindow{
    Q_OBJECT
private:
    QString currentFileName;
public: mainwindow();
    helpdialog *hd;
    mediaobject *m;
public slots:
    void helpShow();
    void addFiles();
    void playCurrent();
    void pauseFile();
    void stopFile();
};

#endif // MAINWINDOW_H
