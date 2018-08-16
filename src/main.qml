import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import com.birdie.canary 1.0
import com.birdie.content 1.0
import QtQuick.Controls 1.4

Window {
    property var sourceList: contentManager.slideSources
    property int slideIndex: 1

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
        Component.onCompleted: console.log(sources)
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width*.8
        height: parent.height*.8
    }

}
