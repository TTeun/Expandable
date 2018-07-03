#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _centralWidget(new CentralWidget) {
  ui->setupUi(this);
  setCentralWidget(_centralWidget);
  resize(1000, 800);
}

MainWindow::~MainWindow() {
  delete ui;
}
