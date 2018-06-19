#include "mainwindow.h"

#include <QGroupBox>
#include <QPushButton>

static const char* styleSheetString =
    "QPushButton{"
    "  Text-align:left;"
    "  background-color: rgb(150,150,150)"
    "}"
    "QPushButton:hover{ "
    "  background-color: rgb(160,150,150)"
    "}"
    "QPushButton:focus{ "
    "  background-color: rgb(150,150,150)"
    "}"
    "QGroupBox {"
    "  background-color: rgb(240,240,240);"
    "}"
    "QWidget#vectorWidget {"
    "  background-color: rgb(240,240,240);"
    "}";

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  setCentralWidget(new CentralWidget(this));
  resize(1200, 800);
  setWindowTitle("GoPhEr");
  setStyleSheet(styleSheetString);
}

MainWindow::~MainWindow() {
}
