#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QMovie>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include <QComboBox>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{

    ui->setupUi(this);
    //gif图移动
    QMovie * movie = new QMovie(":/img/thanks.gif");
    ui->gif_Label->setMovie(movie);
    movie->start();


    //计算按钮
    connect(ui->toolButton_sum, &QToolButton::clicked, this, &MainWidget::getLabelValue);



    //基本工资栏
    connect(ui->lineEdit_19, &QLineEdit::textChanged,ui->textBrowser, [=]()
    {
        int sum = ui->lineEdit_19->text().toInt() * ui->comboBox_multiple->currentText().toUInt();
        QString s = QString::number(sum,10);
        ui->textBrowser->setText(s);
    });

    connect(ui->comboBox_multiple, &QComboBox::currentTextChanged,ui->textBrowser, [=]() {
                int sum = ui->lineEdit_19->text().toInt() * ui->comboBox_multiple->currentText().toUInt();
                QString s = QString::number(sum,10);
                ui->textBrowser->setText(s);
     });

    connect(ui->comboBox_4, &QComboBox::currentTextChanged,ui->textBrowser_2, [=]() {
                int sum = ui->lineEdit_19->text().toInt() * ui->comboBox_4->currentText().toUInt();
                QString s = QString::number(sum,10);
                ui->textBrowser_2->setText(s);
     });


}

//点击按钮获取到各项的值
void MainWidget::getLabelValue() //获取label的值
{
       int addsum = 0;
       int sum = 0;
       addsum += ui->lineEdit_base_money->text().toInt();
       addsum += ui->lineEdit_7->text().toInt();
       addsum += ui->lineEdit_8->text().toInt();
       addsum += ui->lineEdit->text().toInt();
       addsum += ui->lineEdit_6->text().toInt();
       addsum += ui->lineEdit_2->text().toInt();
       addsum += ui->lineEdit_14->text().toInt();
       qDebug()<<"加项=="<<addsum;

       int cutsum = 0;
       cutsum += ui->lineEdit_9->text().toInt();
       cutsum += ui->lineEdit_10->text().toInt();
       cutsum += ui->lineEdit_13->text().toInt();
       cutsum += ui->lineEdit_15->text().toInt();
       cutsum += ui->lineEdit_16->text().toInt();
       cutsum += ui->lineEdit_12->text().toInt();
       qDebug()<<"减项=="<<cutsum;
       sum = addsum - cutsum;
       ui->lcdNumber_2->display(sum);
}

void MainWidget::sumValue() //计算结果
{
    int sum = ui->lineEdit_19->text().toInt() * ui->comboBox_multiple->currentText().toUInt();
    QString s = QString::number(sum,10);
    ui->textBrowser->setText(s);
};
MainWidget::~MainWidget()
{
    delete ui;
}
