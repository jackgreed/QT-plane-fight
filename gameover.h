#ifndef GAMEOVER_H
#define GAMEOVER_H
#include<QVector>
#include <QDialog>

namespace Ui {
class gameover;
}

class gameover : public QDialog
{
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = nullptr);
    ~gameover();
    QVector<QPair<QString,int>>scoreList;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::gameover *ui;
};

#endif // GAMEOVER_H
