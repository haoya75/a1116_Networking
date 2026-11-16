#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    totalBytes = 0;
    byteReceived = 0;
    fileNameSize = 0;
    ServerProgressBar = new QProgressBar;
    serverStatusLabel = new QLabel(tr("伺服器端就緒"));
    startButton = new QPushButton(tr("接收"));
    quitButton = new QPushButton(tr("退出"));
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton,QDialogButtonBox::RejectRole);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ServerProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("接收檔案"));
}

Dialog::~Dialog() = default;

void Dialog::start(){

}

void Dialog::acceptConnection(){

}

void Dialog::updateServerProgress(){

}

void Dialog::displayError(QAbstractSocket::SocketError socketError){

}
