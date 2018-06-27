#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThreadPool>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->verticalSlider_volume, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));
    connect(ui->verticalSlider_rate, SIGNAL(valueChanged(int)), this, SLOT(setRate(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeLineEditTest()
{

    //m_tts.speakChinese("这是一个测试例子!");

    //textspeech.speak("这是一个测试例子!");
}

void MainWindow::on_pushButton_clicked()
{
    int introw = 0;

    QList<QTableWidgetItem*>items=ui->tableWidget->selectedItems();
    if(items.count()>0)
    {
        introw = ui->tableWidget->row(items.at(0));//获取选中的行
        introw ++ ;
    }
    else
    {
        introw = 0;
    }

    on_tableWidget_cellClicked(introw, 0);
}


void MainWindow::readExcel()
{

}

void MainWindow::on_Btn_import_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Excel"), ".", tr("Image Files(*.xls)"));
    if(path.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        //QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
        ui->tableWidget->clear();
        ExcelEngine excel(path);
        excel.Open(1,true);
        excel.ReadDataToTable(ui->tableWidget); //导入到widget中
        excel.Close();
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString str_studentId = ui->tableWidget->item(row,1)->text();
    ui->tableWidget->selectRow(row);

    if(ui->checkBox_class->isChecked())
    {
        textspeech.speak(ui->tableWidget->item(row,0)->text()+"班");
    }

    if(ui->checkBox_studentId->isChecked())
    {
        str_studentId = ui->tableWidget->item(row,1)->text();

        textspeech.speak(str_studentId.right(3));
    }

    ui->lcdNumber->display(ui->tableWidget->item(row,1)->text());
    ui->label_name->setText(ui->tableWidget->item(row,2)->text());
    textspeech.speak(ui->tableWidget->item(row,2)->text());
}

void MainWindow::setVolume(int vallue)
{
    textspeech.setVolume(vallue);
}

void MainWindow::setRate(int vallue)
{
    textspeech.setRate(vallue);
}

void MainWindow::on_pushButton_Test_clicked()
{
    textspeech.speak(tr("音量测试"));
}

void MainWindow::on_pushButton_Read_clicked()
{
    textspeech.speak(ui->plainTextEdit_Read->toPlainText());
}

void MainWindow::on_pushButton_management_clicked()
{
    QString str_rule="成都东软学院课堂教学管理规定\n \
    第一条，学生不得旷课、迟到、早退，否则按学院相关规定处理；\n \
    第二条，学生进入教室，必须衣冠整洁，不准穿拖鞋、背心进入教室及办公、教学楼。如果发现，必须立即整改后方能进入教室及办公、教学楼；\n \
    第三条，学生上课时，不准将食物带入教室，不准在教室吃零食。\n \
    第四条,学生进入教室后，应按任课教师所指定的位置入座，做到整齐统一。\n \
    第五条，上课铃响后，必须关闭手机。\n \
    第六条，上课前，任课教师对学生进行考勤，学生应当尊重教师对学生的点名，凡点到学生的姓名后，应举手答“到”，不准使用其他不尊重老师的用语。\n \
    第七条，学生应在课堂中端正坐姿，不准趴在课桌上，严禁在上课期间睡觉。禁止看小说、杂志、听电子音乐、打游戏等与课堂教学无关的事情。对违纪者，任课教师应记载作为平时考核的依据。\n \
    第八条，课堂中，任课老师在纠正学生违纪行为时，学生应服从管理，不准当面顶撞，更不准使用不文明语言与任课教师发生争执。课堂上不服从管理者，交学院相关部门严肃处理。\n \
    第九条，课堂上，学生是否使用笔记本电脑或何时使用笔记本电脑，由任课教师根据课程内容统一要求，未经任课教师的许可，学生不准擅自使用笔记本电脑。\n \
    第十条，课堂上，学生在使用电脑做练习时，禁止玩游戏及其他与课堂教学无关的事项。如有发现则按学院有关规定严肃处理。\n \
    第十一条，学生应按时完成任课教师布置的学习任务。\n \
    第十二条，对学生旷课的处理： \n \
     （一），旷课10个学时者，给予警告处分； \n \
     （二），旷课20个学时者，给予严重警告处分；\n \
     （三），旷课30个学时者，给予记过处分； \n \
     （四），旷课40个学时及以上者，给予留校察看处分。\n \
     （五），针对某单门课程旷课学时达到一定比例，由教务部门参照相关教务、教学管理条款规定执行。以上 （一）至 （五）款的学时数均以一学期累计算。\n \
     （六），无故不参加学校组织的教育教学活动或擅自离校者，每天按旷课 6学时计算； \n \
     （七），迟到、早退 20分钟及以上按旷课 1学时计算。\n \
    本规定自发布之日起执行，其它与之相冲突的规定条款，以本规定为准。";

   ui->plainTextEdit_Read->setPlainText(str_rule);

}
