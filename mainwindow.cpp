#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ctime"
#include "QString"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	createConnection();

    model = new QSqlTableModel(this, db);
    model->setTable("Result");
    model->select();

	model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Врмя начала движения"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Продолжительность втягивания"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Глубина походного порядка"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("Продолжительность марша"));

	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	ui->tableView->setModel(model);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	ui->lineEdit->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_8->clear();
	ui->lineEdit_9->clear();
	ui->lineEdit_10->clear();
	ui->lineEdit_11->clear();
	ui->lineEdit_12->clear();
	ui->lineEdit_13->clear();
	ui->lineEdit_14->clear();
	ui->lineEdit_15->clear();
	ui->lineEdit_16->clear();
	ui->lineEdit_17->clear();
	ui->lineEdit_18->clear();
}

void MainWindow::on_lineEdit_14_textEdited(const QString &arg1)
{
    QString s = ui->lineEdit_14->text();
    QString t = ui->lineEdit_15->text();
    QString Ost = ui->lineEdit_16->text();
    QString Vtyag = ui->lineEdit_17->text();

    ui->lineEdit_18->setText( QString::number((s.toFloat() / t.toFloat()) - Ost.toFloat()));
}

void MainWindow::on_lineEdit_15_textEdited(const QString &arg1)
{
    QString s = ui->lineEdit_14->text();
    QString t = ui->lineEdit_15->text();
    QString Ost = ui->lineEdit_16->text();
    QString Vtyag = ui->lineEdit_17->text();

    ui->lineEdit_18->setText( QString::number((s.toFloat() / t.toFloat()) - Ost.toFloat()));
}

void MainWindow::on_lineEdit_16_textEdited(const QString &arg1)
{
    QString s = ui->lineEdit_14->text();
    QString t = ui->lineEdit_15->text();
    QString Ost = ui->lineEdit_16->text();
    QString Vtyag = ui->lineEdit_17->text();

    ui->lineEdit_18->setText( QString::number((s.toFloat() / t.toFloat()) - Ost.toFloat()));
}

void MainWindow::on_lineEdit_17_textEdited(const QString &arg1)
{
    QString s = ui->lineEdit_14->text();
    QString t = ui->lineEdit_15->text();
    QString Ost = ui->lineEdit_16->text();
    QString Vtyag = ui->lineEdit_17->text();

    ui->lineEdit_18->setText( QString::number((s.toFloat() / t.toFloat()) - Ost.toFloat()));
}

void MainWindow::on_saveBt_clicked()
{
	QSqlQuery query;

	query.exec("insert into Result (begin, timev, dist, timem)"
			   "values ('" + ui->lineEdit->text()+ "', '" +
				ui->lineEdit_8->text() + "', '" +
				ui->lineEdit_13->text() + "', '" +
				ui->lineEdit_18->text() + "')");

	model->select();
}

void MainWindow::nultext4() // расчет продолжительности вытягивания
{
    if (ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="" && ui->lineEdit_3->text()!="")
    {
        ui->lineEdit_4->setText("working"); //расчет вместо этой строки
    } else ui->lineEdit_4->setText("");
}
void MainWindow::nultext8() //расчет продолжительности втягивания
{
    if (ui->lineEdit_5->text()!="" && ui->lineEdit_6->text()!="" && ui->lineEdit_7->text()!="")
    {
        ui->lineEdit_8->setText("working"); //расчет вместо этой строки
    } else ui->lineEdit_8->setText("");
    ui->lineEdit_17->setText(ui->lineEdit_8->text());
}
void MainWindow::nultext13() // расчет глубины походного порядка
{
    if (ui->lineEdit_9->text()!="" && ui->lineEdit_10->text()!="" && ui->lineEdit_11->text()!="" && ui->lineEdit_12->text()!="")
    {
        ui->lineEdit_13->setText("working"); //расчет вместо этой строки
    } else ui->lineEdit_13->setText("");

    ui->lineEdit_5->setText(ui->lineEdit_13->text());
}
void MainWindow::nultext18() // расчет продолжительности марша
{
    if (ui->lineEdit_14->text()!="" && ui->lineEdit_15->text()!="" && ui->lineEdit_16->text()!="" && ui->lineEdit_17->text()!="")
    {
        ui->lineEdit_18->setText("working"); //расчет вместо этой строки
    } else ui->lineEdit_18->setText("");
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    MainWindow::nultext4();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    MainWindow::nultext4();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    MainWindow::nultext4();
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    MainWindow::nultext8();
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    MainWindow::nultext8();
}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    MainWindow::nultext8();
}

void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    MainWindow::nultext13();
}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    MainWindow::nultext13();
}

void MainWindow::on_lineEdit_11_textChanged(const QString &arg1)
{
    MainWindow::nultext13();
}

void MainWindow::on_lineEdit_12_textChanged(const QString &arg1)
{
    MainWindow::nultext13();
}

void MainWindow::on_lineEdit_14_textChanged(const QString &arg1)
{
    MainWindow::nultext18();
}

void MainWindow::on_lineEdit_15_textChanged(const QString &arg1)
{
    MainWindow::nultext18();
}

void MainWindow::on_lineEdit_16_textChanged(const QString &arg1)
{
    MainWindow::nultext18();
}

void MainWindow::on_lineEdit_17_textChanged(const QString &arg1)
{
    MainWindow::nultext18();
}

