#include "sudokuWidget.h"
#include "processDlg.h"
#include "conformDlg.h"
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QHostAddress>
#include <QUdpSocket>

void sudokuMain::mainTimerUp()
{
    strTime = QString(":");
    strTime.push_front(QString(m_iTimeMinute%10+'0'));
    strTime.push_front(QString((m_iTimeMinute%100)/10+'0'));
    strTime.push_back(QString((m_iTimeSecond%100)/10+'0'));
    strTime.push_back(QString(m_iTimeSecond%10+'0'));
    lcdNumber->display(QString(strTime));
    m_iTimeSecond++;
    if(m_iTimeSecond>=60)
    {
        m_iTimeSecond = 0;
        m_iTimeMinute++;
        if(m_iTimeMinute>=60)
        {
            m_iTimeMinute = 0;
        }
    }
}

void sudokuMain::clickTimerUp()
{
    if(m_time_between_click!=0)
    {
        m_time_between_click++;
        if(m_time_between_click>2)//Isn't Double Click
        {
            m_time_between_click = 0;
        }
    }
}

void sudokuMain::connectTimerUp()
{
    if(m_processDlg->m_bCanceled || m_processDlg->m_bConnected)
    {
        m_processDlg->m_Timer.stop();
        connect_Timer->stop();
        if(m_processDlg->m_bConnected)
        {
            this->setVisible(TRUE);
            m_processDlg->close();
        }
        else if(m_processDlg->m_bCanceled)
        {
            this->setVisible(TRUE);
            m_processDlg->close();
            resetTable();
        }
    }
}

void sudokuMain::changeTheme(const QString & text)
{
    if(text != m_curTheme)
    {
        //Change Setting
        if(text == QString(tr("数字")))
        {
            m_cTheme = 'N';
            m_curTheme = QString(tr("数字"));
        }
        else if(text == QString(tr("太阳系")))
        {
            m_cTheme = 'S';
            m_curTheme = QString(tr("太阳系"));
        }
        else if(text == QString(tr("表情")))
        {
            m_cTheme = 'F';
            m_curTheme = QString(tr("表情"));
        }
        else if(text == QString(tr("元素")))
        {
            m_cTheme = 'E';
            m_curTheme = QString(tr("元素"));
        }
        //Change Side Button Theme
        setButtonNum(pB1,1,30);
        setButtonNum(pB2,2,30);
        setButtonNum(pB3,3,30);
        setButtonNum(pB4,4,30);
        setButtonNum(pB5,5,30);
        setButtonNum(pB6,6,30);
        setButtonNum(pB7,7,30);
        setButtonNum(pB8,8,30);
        setButtonNum(pB9,9,30);
        int i,j;
        QPushButton *pB;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(table[i][j][0]!=0)
                {
                    pB = getPointFromPosition(i+1,j+1);
                    setButtonNum(pB,table[i][j][0],40);
                }
            }
        }
        if(m_iSetNum!=0)
        {
            QPushButton *pB_side = getPointFromNumber(m_iSetNum);
            pB_side->setIconSize(QSize(40,40));
        }
    }
}

void sudokuMain::changeBackground(const QString & text)
{
    if(text != m_curBackground)
    {
        //Change Setting
        if(text == QString(tr("木质格调")))
        {
            m_cBackground = 'M';
            m_curBackground = QString(tr("木质格调"));
        }
        else if(text == QString(tr("夏日风情")))
        {
            m_cBackground = 'X';
            m_curBackground = QString(tr("夏日风情"));
        }
        else if(text == QString(tr("绿意盎然")))
        {
            m_cBackground = 'G';
            m_curBackground = QString(tr("绿意盎然"));
        }
        else if(text == QString(tr("红旗永驻")))
        {
            m_cBackground = 'R';
            m_curBackground = QString(tr("红旗永驻"));
        }
        //Change Background Image
        QPalette palette = this->palette();
        QString bg = QString::fromUtf8(":/png/");
        bg.push_back(m_cBackground);
        bg.push_back(QString::fromUtf8(".png"));
        QPixmap pic(QPixmap::fromImage(QImage(bg)));
        QBrush *pBrush = new QBrush(pic);
        palette.setBrush(QPalette::Background, *pBrush);
        this->setPalette(palette);
    }
}

void sudokuMain::enableIP()
{
    if(rB_single->isChecked())
    {
        lineEdit_IP->setVisible(FALSE);
        progressBar_2->setVisible(FALSE);
        label_ip->setVisible(FALSE);
        label_p2->setVisible(FALSE);
        label_p1->setText(QString(tr("^_^ :")));
        label_p2->setText(QString(tr("")));
    }
    else if(rB_online->isChecked())
    {
        lineEdit_IP->setVisible(TRUE);
        progressBar_2->setVisible(TRUE);
        label_ip->setVisible(TRUE);
        label_p2->setVisible(TRUE);
        label_p1->setText(QString(tr("己方:")));
        label_p2->setText(QString(tr("对方:")));
    }
}


void sudokuMain::showTable()
{
    int L,R;
    QPushButton* pB;
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            if(table[L][R][0]!=0)
            {
                //Show Table
                pB = getPointFromPosition(L+1,R+1);
                setButtonNum(pB,table[L][R][0],40);
                pB->setFlat(TRUE);
                writable[L][R] = 0;
            }
        }
    }
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            //Unlock Table
            writableLock[L][R] = writable[L][R];
            writable[L][R] = 0;//Alter After Being Setted ,Protect "table"
        }
    }
    int val = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
    progressBar_1->setValue(val);
    m_bLocked = FALSE;
    pB_setTable->setHidden(TRUE);
    pB_fileSet->setHidden(TRUE);
    pB_autoSet->setHidden(TRUE);
    pB_start->setHidden(FALSE);
    pB_resetTable->setHidden(FALSE);
    pB_giveUp->setHidden(FALSE);
    pB_resetTable->setDisabled(FALSE);
    pB_start->setDisabled(FALSE);
    pB_giveUp->setDisabled(TRUE);
    m_processDlg->m_bConnected = TRUE;
    startGame();
}

void sudokuMain::processPendingDatagrams()
{
    int val;
    QByteArray datagram;
    do {
        datagram.resize(udpReceiver.pendingDatagramSize());
        udpReceiver.readDatagram(datagram.data(), datagram.size());
    } while (udpReceiver.hasPendingDatagrams());
    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_5);
    in >> val;
    if(val>=0&&val<=100 && rB_online->isChecked())
    {
        progressBar_2->setValue(val);
    }
    else if(val==MES_REQUEST && rB_online->isChecked())
    {
        conformDlg con;
        bool ok = con.makeMode();
        QString ip;
        ip = lineEdit_IP->text();
        if(ip==QString(tr(("127.0.0.1"))))
        {
            QMessageBox finish(QMessageBox::Information,QString(tr("提示")),QString(tr("不允许连接本机与本机连接!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            finish.exec();
            return;
        }
        if(ip.endsWith(QString(tr(".0")))||ip.endsWith(QString(tr(".255"))))
        {
            QMessageBox finish(QMessageBox::Information,QString(tr("提示")),QString(tr("请输入有效的对方主机地址!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            finish.exec();
            return;
        }
        if(ok)
        {
            sendDatagram(MES_CONFIRM);//Confirm Connect
        }
        else
        {
            sendDatagram(MES_REJECT);//Reject Connect
        }
    }
    else if(val==MES_REJECT && rB_online->isChecked())
    {
        m_processDlg->m_bCanceled = TRUE;
        resetTable();
        QMessageBox re(QMessageBox::Information,QString(tr("提示")),QString(tr("对方拒绝了你的连接请求!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        re.exec();
    }
    else if(val==MES_CONFIRM && rB_online->isChecked())
    {
        int i,j;
        QByteArray datagram;
        QDataStream out(&datagram, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_5);
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                out << table[i][j][0]+1000;
            }
        }
        QString ip;
        ip = lineEdit_IP->text();
        udpSender.writeDatagram(datagram, QHostAddress(ip), 5824);//Send The Table
    }
    else if(val>=1000 && val<1010 && rB_online->isChecked())
    {
        int i,j;
        table[0][0][0] = val-1000;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(i==0 && j==0)
                {
                    continue;//Ignore [0][0]
                }
                in >> table[i][j][0];
                table[i][j][0]-=1000;
            }
        }
        sendDatagram(MES_FINISH);//Finish Receive Table
        showTable();
    }
    else if(val==MES_FINISH && rB_online->isChecked())
    {
        m_processDlg->m_bConnected = TRUE;
        startGame();
    }
    else if(val==MES_GIVEUP && rB_online->isChecked())
    {
        int i,j;
        main_Timer->stop();
        m_blankNumber = -1;
        m_beginPorgressBar = FALSE;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                table[i][j][0] = solution[i][j];
                setButtonNum(getPointFromPosition(i+1,j+1),table[i][j][0],40);
            }
        }
        m_bFinished = TRUE;
        m_processDlg->m_bConnected = FALSE;
        pB_giveUp->setText(QString(tr("完成")));
        progressBar_1->setValue(100);
        QMessageBox finish(QMessageBox::Information,QString(tr("胜利")),QString(tr("你的对手向你认输了^^!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        finish.exec();
    }
    else if(val==MES_WIN && rB_online->isChecked())
    {
        int i,j;
        main_Timer->stop();
        m_blankNumber = -1;
        m_beginPorgressBar = FALSE;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                table[i][j][0] = 0;
                setButtonNum(getPointFromPosition(i+1,j+1),table[i][j][0],40);
            }
        }
        m_bFinished = TRUE;
        m_processDlg->m_bConnected = FALSE;
        pB_giveUp->setText(QString(tr("失败")));
        QMessageBox finish(QMessageBox::Information,QString(tr("失败")),QString(tr("这次你败给了对手，再接再厉!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        finish.exec();
    }
}

void sudokuMain::sendDatagram(int message)
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_5);
    out << message;

    QString ip;
    ip = lineEdit_IP->text();
    udpSender.writeDatagram(datagram, QHostAddress(ip), 5824);
}
