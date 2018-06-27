#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "q_tts.h"
#include "testspeech.h"
#include "excelengine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void readExcel();

private slots:
    void on_pushButton_clicked();
    void changeLineEditTest();

    void on_Btn_import_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void setVolume(int);
    void setRate(int);

    void on_pushButton_Test_clicked();

    void on_pushButton_Read_clicked();

    void on_pushButton_management_clicked();

private:
    Ui::MainWindow *ui;

    Q_TTS m_tts;
    TextSpeech textspeech;
};

#endif // MAINWINDOW_H
