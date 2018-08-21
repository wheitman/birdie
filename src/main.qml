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

    BirdieQtTools{

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

    function moveToNextSlide(){
        //check for out-of-bounds
        if(slideIndex === sourceList.length){
            slideIndex=0 //loop back around
            slides.clear()
        }
        console.log(slideIndex)
        if(slides.get(0)===slideImageA){
            console.log('Pushing B')
            slideImageB.source = "file:/C:/slides/"+sourceList[slideIndex]
            slides.clear()
            slides.push(slideImageB)
            //slides.pop(slideImageA)
            slideIndex++
        }
        else{
            console.log("Pushing A")
            slideImageA.source = "file:C:/slides/"+sourceList[slideIndex]
            slides.clear()
            slides.push(slideImageA)
            //slides.pop(slideImageB)
            slideIndex++
        }
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

    Button {
        anchors.bottom: parent.bottom
        id: helloWorld
        text: "Hello, World!"
        objectName: "helloWorld"
        onClicked: {
            slideFrame.nextSlide()
        }
    }

    SlideFrame{
        id: slideFrame
        sources: sourceList
        slideDir: contentManager.slideDir
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width*.8
        height: parent.height*.8
    }

    Ticker {
        id: ticker
        anchors.top: slideFrame.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height*.08
    }

}
