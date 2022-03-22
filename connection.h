#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

static QSqlDatabase db;

static bool createConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb, *.accdb)};  FIL={MS Access};"
					   "DBQ=C:/Users/Olymp2/Documents/untitled3/MyDB.accdb");

	if (!db.open()) {
		QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
			db.lastError().text(), QMessageBox::Cancel);
		return false;
	}
	return true;
}

#endif // CONNECTION_H
