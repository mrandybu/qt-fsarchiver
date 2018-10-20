/*
 * qt-fsarchiver: Filesystem Archiver
 * 
* Copyright (C) 2008-2018 Dieter Baum.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 */

#ifndef DIR_H
#define DIR_H
#include <QtGui>
#include <QFileSystemModel>
#include <QMessageBox>
#include <string.h>
#include "ui_dir_dialog.h"
#include "thread.h"
using namespace std;

class DialogDIR : public QWidget, private Ui::dir_dialog
{
	Q_OBJECT

public:
	DialogDIR(QWidget *parent = 0);

public slots:
	int folder_dir_path_einlesen();
        void treeview_show();
        void zip_einlesen_dir(); 
              
private:
    QFileSystemModel *dirModel;
    QItemSelectionModel *selModel;
    QFileSystemModel *dirModel1;
    QItemSelectionModel *selModel1;
    QLabel *questionLabel;
    void indicator_reset();
    QTimer *timer;

protected slots:
    void elapsedTime();
    void remainingTime(int prozent);
    void chkkey();
    void ViewProzent();
    int questionMessage(QString frage);
    void chkhidden();
    void save_attribut_dir(QString attribut);
    QString datei_auswerten_dir(QString buchstabe);
    QString datei_auswerten_1_dir(QString dateiname);
              
private slots:    
   void thread1Ready();
   void thread2Ready();
	
};

#endif










