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
from PyQt5.QtGui import QPixmap
from PyQt5 import QtGui, QtSvg


class CanaryAlert(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()
        self.paintUI()

    def toggleFS(self):

        if self.isFullScreen():
            self.showNormal()
        else:
            self.showFullScreen()

    def initUI(self):

        self.setGeometry(100,100,960,540)

    def paintUI(self):

        toggleFullscreen = QPushButton(text="Fullscreen")
        toggleFullscreen.setCheckable(True)
        toggleFullscreen.toggle()

        grid = QGridLayout()
        grid.setSpacing(0)
        grid.setContentsMargins(0, 0, 0, 0)

        toggleFullscreen.clicked.connect(self.toggleFS)

        #18 x 32 cells with 60px per cell
        self.setLayout(grid)

        banner = QWidget()
        banner.setStyleSheet("background: rgb(255,228,0)")
        bannerImg = QLabel(banner)
        bannerImg.setPixmap(QPixmap("res/banner_100.png"))
        bannerImg.setScaledContents(True)
        bannerImg.setSizePolicy(QSizePolicy.Maximum, QSizePolicy.Maximum)

        icon = QtSvg.QSvgWidget("res/pause.svg")
        icon.setGeometry(50,50,100,100)

        message = QLabel("Sign-Out paused.")

        grid.addWidget(banner, 0, 0, 2, 32)
        grid.addWidget(bannerImg, 0, 0, 2, 17)
        grid.addWidget(icon, 5, 1, 10, 10)
        grid.addWidget(message, 4, 13, 14, 16)

        self.setWindowTitle("Birdie")
        self.show()

    def resizeEvent(self, a0: QtGui.QResizeEvent):

        self.paintUI()
        print("initing")


if __name__ == '__main__':
    app = QApplication(sys.argv)
    alert = CanaryAlert()
    sys.exit(app.exec_())