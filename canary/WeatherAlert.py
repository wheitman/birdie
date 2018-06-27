#!/usr/bin/python3
# -*- coding: utf-8 -*-

"""
ZetCode PyQt5 tutorial

In this example, we create a bit
more complicated window layout using
the QGridLayout manager.

author: Jan Bodnar
website: zetcode.com
last edited: January 2015
"""

import sys
from PyQt5.QtWidgets import (QWidget, QLabel, QLineEdit,
                             QTextEdit, QGridLayout, QApplication, QPushButton)
from PyQt5.QtGui import QColor, QPainter

class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def toggleFS(self):

        if(self.isFullScreen()):
            self.showNormal()
        else:
            self.showFullScreen()

    def initUI(self):

        toggleFullscreen = QPushButton(text="Fullscreen")
        toggleFullscreen.setCheckable(True)
        toggleFullscreen.toggle()

        grid = QGridLayout()
        grid.setSpacing(0)

        toggleFullscreen.clicked.connect(self.toggleFS)

        self.setLayout(grid)
        self.setGeometry(300,300,960,540)

        banner = QLabel("Canary Alert System")
        banner.setStyleSheet("background: rgb(255,228,0)")
        grid.addWidget(banner,0,0)

        self.setWindowTitle("Canary")
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())