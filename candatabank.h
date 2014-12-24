#ifndef CANDATABANK_H
#define CANDATABANK_H

#include <QWidget>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVector>

namespace Ui {
class CANdatabank;
}

class CANdatabank : public QWidget
{
    Q_OBJECT

public:
    explicit CANdatabank(QWidget *parent = 0);
    ~CANdatabank();
private slots:
    void DBC_browsefile();
private:
    QString fileName;
    Ui::CANdatabank *ui;
    QSqlDatabase mydb =  QSqlDatabase::addDatabase("QSQLITE");
    int OKdataBankFlag;
public slots:
    QString CANFrameName(quint32 CANid);
    QVector<QStringList> CANSignalList(quint32 CANid);
    int returnOKdataBankFlag();
};

#endif // CANDATABANK_H
