#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
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
		QString n = ui->lineEdit->text();
			QString s = ui->lineEdit_2->text();
			QString t = ui->lineEdit_3->text();
			QString h = n.left(2);
			QString m = n.right(2);
			QString m2 = NULL;
			int t1 = h.toInt()*60 + m.toInt() - (s.toFloat()/t.toFloat()*60);
			int h1 = t1/60;
				 if (h1 < 0)
					 h1 += 23;
			int m1 = t1%60;
				 if (m1 < 0)
					 m1 += 60;
			if (m1<10)
			  { m2 = QString::number(m1);
				m2.insert(0, "0");
			  }
			else m2 = QString::number(m1);

			ui->lineEdit_4->setText(QString::number(h1)+":"+m2);
	} else ui->lineEdit_4->setText("");
}
void MainWindow::nultext8() //расчет продолжительности втягивания
{
	if (ui->lineEdit_5->text()!="" && ui->lineEdit_6->text()!="" && ui->lineEdit_7->text()!="")
	{
		QString pp = ui->lineEdit_5->text();
		QString rs = ui->lineEdit_6->text();
		QString v = ui->lineEdit_7->text();

		ui->lineEdit_8->setText(QString::number(round(60*(pp.toFloat()-rs.toFloat())/v.toFloat())));

	} else ui->lineEdit_8->setText("");
	float a=round(ui->lineEdit_8->text().toFloat()/6)/10;
	ui->lineEdit_17->setText(QString::number((a)));
}
void MainWindow::nultext13() // расчет глубины походного порядка
{
	if (ui->lineEdit_9->text()!="" && ui->lineEdit_10->text()!="" && ui->lineEdit_11->text()!="" && ui->lineEdit_12->text()!="")
	{
		  QString n = ui->lineEdit_9->text();
		  QString nd = ui->lineEdit_10->text();
		  QString c = ui->lineEdit_11->text();
		  QString cd = ui->lineEdit_12->text();
		  float d = ((n.toFloat()*nd.toFloat() + (c.toFloat()-1) * cd.toFloat())/100);


		  ui->lineEdit_13->setText(QString::number((d-remainder(d,1))/10));
	} else ui->lineEdit_13->setText("");

	ui->lineEdit_5->setText(ui->lineEdit_13->text());
}
void MainWindow::nultext18() // расчет продолжительности марша
{
	if (ui->lineEdit_14->text()!="" && ui->lineEdit_15->text()!="" && ui->lineEdit_16->text()!="" && ui->lineEdit_17->text()!="")
	{
		QString s = ui->lineEdit_14->text();
		QString t = ui->lineEdit_15->text();
		QString Ost = ui->lineEdit_16->text();
		QString Vtyag = ui->lineEdit_17->text();
		ui->lineEdit_18->setText(QString::number(round((s.toFloat() / t.toFloat() + Ost.toFloat() + Vtyag.toFloat())*10)/10));
	} else ui->lineEdit_18->setText("");
}

void MainWindow::on_lineEdit_3_textChanged()
{
	MainWindow::nultext4();
}

void MainWindow::on_lineEdit_2_textChanged()
{
	MainWindow::nultext4();
}

void MainWindow::on_lineEdit_textChanged()
{
	MainWindow::nultext4();
}

void MainWindow::on_lineEdit_5_textChanged()
{
	MainWindow::nultext8();
}

void MainWindow::on_lineEdit_6_textChanged()
{
	MainWindow::nultext8();
}

void MainWindow::on_lineEdit_7_textChanged()
{
	MainWindow::nultext8();
}

void MainWindow::on_lineEdit_9_textChanged()
{
	MainWindow::nultext13();
}

void MainWindow::on_lineEdit_10_textChanged()
{
	MainWindow::nultext13();
}

void MainWindow::on_lineEdit_11_textChanged()
{
	MainWindow::nultext13();
}

void MainWindow::on_lineEdit_12_textChanged()
{
	MainWindow::nultext13();
}

void MainWindow::on_lineEdit_14_textChanged()
{
	MainWindow::nultext18();
}

void MainWindow::on_lineEdit_15_textChanged()
{
	MainWindow::nultext18();
}

void MainWindow::on_lineEdit_16_textChanged()
{
	MainWindow::nultext18();
}

void MainWindow::on_lineEdit_17_textChanged()
{
	MainWindow::nultext18();
}
