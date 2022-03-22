#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
//#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

        void on_saveBt_clicked();

    void on_lineEdit_3_textChanged(const QString);
    void nultext4();
    void nultext8();
    void nultext13();
    void nultext18();
    void on_lineEdit_2_textChanged(const QString);

    void on_lineEdit_textChanged(const QString);

    void on_lineEdit_5_textChanged(const QString);

    void on_lineEdit_6_textChanged(const QString );

    void on_lineEdit_7_textChanged(const QString);

    void on_lineEdit_9_textChanged(const QString);

    void on_lineEdit_10_textChanged(const QString);

    void on_lineEdit_11_textChanged(const QString);

    void on_lineEdit_12_textChanged(const QString);

    void on_lineEdit_14_textChanged(const QString);

    void on_lineEdit_15_textChanged(const QString);

    void on_lineEdit_16_textChanged(const QString);

    void on_lineEdit_17_textChanged(const QString);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;

};
#endif // MAINWINDOW_H
