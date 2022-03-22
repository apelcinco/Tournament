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

	void on_lineEdit_3_textChanged();
	void nultext4();
	void nultext8();
	void nultext13();
	void nultext18();
	void on_lineEdit_2_textChanged();

	void on_lineEdit_textChanged();

	void on_lineEdit_5_textChanged();

	void on_lineEdit_6_textChanged();

	void on_lineEdit_7_textChanged();

	void on_lineEdit_9_textChanged();

	void on_lineEdit_10_textChanged();

	void on_lineEdit_11_textChanged();

	void on_lineEdit_12_textChanged();

	void on_lineEdit_14_textChanged();

	void on_lineEdit_15_textChanged();

	void on_lineEdit_16_textChanged();

	void on_lineEdit_17_textChanged();

private:
	Ui::MainWindow *ui;
	QSqlTableModel *model;

};
#endif // MAINWINDOW_H
