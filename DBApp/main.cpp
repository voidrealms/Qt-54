#include <QtCore/QCoreApplication>

#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("LOCALHOST\\SQLEXPRESS");
    db.setDatabaseName("mydsn32");

    //%systemdrive%\Windows\SysWoW64\Odbcad32.exe

    if(db.open())
    {
        qDebug() << "Opened";
        db.close();
    }
    else
    {
        qDebug() << db.lastError().text();
    }

    return a.exec();
}
