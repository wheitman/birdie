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
        if(slideIndex == sourceList.length){
            slideIndex=0 //loop back around
        }
        slideImage.source = "file:/C:/slides/"+sourceList[slideIndex]
        slideIndex++
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
            moveToNextSlide()
            console.log(sourceList[slideIndex])
        }
    }

    Image {
        id: slideImage
        asynchronous: true
        source: "file:/C:/slides/"+sourceList[0]
    }

    StackView {
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width*.8
        height: parent.height*.8
        id: slides
        initialItem: slideImage
        delegate: StackViewDelegate {
            function transitionFinished(properties)
            {
                properties.exitItem.opacity = 1
            }

            pushTransition: StackViewTransition {
                PropertyAnimation {
                    target: enterItem
                    property: "opacity"
                    from: 0
                    to: 1
                    duration: 2000
                }
                PropertyAnimation {
                    target: exitItem
                    property: "opacity"
                    from: 1
                    to: 0
                    duration: 2000
                }
            }
        }
    }
}
