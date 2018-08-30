import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import com.birdie.canary 1.0
import com.birdie.content 1.0
import QtQuick.Controls 1.4
import com.birdie.qttools 1.0

Window {
    property var sourceList: contentManager.slideSources
    property string slideDir: contentManager.slideDir
    property int slideIndex: 1
    property string manifestString: tools.manifestString

    BirdieQtTools{
        id: tools
    }

    Timer {
        id: slideTimer
        interval: 5000; running: true; repeat: true
        onTriggered: {slideFrame.nextSlide()
            console.log(tools.manifestString)}
    }

    Canary {
        id: canary
        objectName: "canary"
        onCurrentAlarmChanged: console.log("Current alarm code: "+currentAlarm)
        currentAlarm: 1
    }

    ContentManager {
        id: contentManager
    }

    visible: true
    width: 1280
    height: 720
    title: qsTr("Hello World")

    Image {
        id: backgroundGradient
        source: "qrc:/images/background.png"
        anchors.fill: parent
    }

//    Button {
//        anchors.bottom: parent.bottom
//        id: helloWorld
//        text: "Hello, World!"
//        objectName: "helloWorld"
//        onClicked: {
//            slideFrame.nextSlide()
//        }
//    }

    SlideFrame{
        id: slideFrame
        sources: sourceList
        slideDir: contentManager.slideDir
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width*.8
        height: parent.height*.8
        Component.onCompleted: console.log("Slide directory: "+contentManager.slideDir)
    }

    Ticker {
        id: ticker
        anchors.top: slideFrame.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height*.1
    }

    Image {
        id: lsmsaLogo
        source: "qrc:/images/lsmsa.png"
        anchors.top: ticker.bottom; anchors.bottom: parent.bottom
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
    }



    Clock{
        anchors.right: ticker.right
        anchors.top: ticker.bottom
        anchors.bottom: parent.bottom
        height: parent.height * .1
        width: height*3
    }

    EventsBox {
        anchors.left: slideFrame.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: ticker.top
    }

}
