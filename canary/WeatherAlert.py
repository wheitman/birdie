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

import os, sys
from PyQt5.QtWidgets import (QWidget, QLabel, QLineEdit,
                             QTextEdit, QGridLayout, QApplication, QPushButton, QSizePolicy)
from PyQt5.QtGui import QColor, QPainter, QPixmap


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def toggleFS(self):

        if self.isFullScreen():
            self.showNormal()
        else:
            self.showFullScreen()

    def initUI(self):

        toggleFullscreen = QPushButton(text="Fullscreen")
        toggleFullscreen.setCheckable(True)
        toggleFullscreen.toggle()

        grid = QGridLayout()
        grid.setSpacing(0)
        grid.setContentsMargins(0, 0, 0, 0)

        toggleFullscreen.clicked.connect(self.toggleFS)

        #18 x 32 cells with 60px per cell
        self.setLayout(grid)
        self.setGeometry(300,300,960,540)

        banner = QWidget()
        banner.setStyleSheet("background: rgb(255,228,0)")
        bannerImg = QLabel(banner)
        bannerImg.setPixmap(QPixmap("res/banner_100.png"))
        bannerImg.setScaledContents(True)
        bannerImg.setSizePolicy(QSizePolicy.Maximum, QSizePolicy.Maximum)
        #banner.setMaximumHeight()

        message = QLabel("Sign-Out paused.")

        grid.addWidget(banner, 0, 0, 2, 32)
        grid.addWidget(bannerImg, 0, 0, 2, 17)
        grid.addWidget(message, 4, 13, 14, 16)
        #grid.addWidget(toggleFullscreen, 1, 0)

        self.setWindowTitle("Canary")
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())