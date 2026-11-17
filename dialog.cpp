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
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(&tcpServer, SIGNAL(acceptError(QAbstractSocket::SocketError)), this,SLOT(displayError(QAbstractSocket::SocketError)));
}

Dialog::~Dialog() = default;

void Dialog::start(){
    startButton->setEnabled(false);
    byteReceived = 0;
    fileNameSize = 0;
    while(!tcpServer.isListening() && !tcpServer.listen(QHostAddress::AnyIPv4, 16998)){
        QMessageBox::StandardButton ret = QMessageBox::critical(this,tr("迴圈"),tr("無法啟動伺服器: %1.").arg(tcpServer.errorString()),QMessageBox::Retry | QMessageBox::Cancel);
        if(ret == QMessageBox::Cancel);
    }
    serverStatusLabel->setText(tr("監聽中..."));
}

void Dialog::acceptConnection(){

}

void Dialog::updateServerProgress(){

}

void Dialog::displayError(QAbstractSocket::SocketError socketError){

}
