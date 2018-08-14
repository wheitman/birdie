import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import com.birdie.canary 1.0
import com.birdie.content 1.0
import QtQuick.Controls 1.4

Window {
    property string slideSources: ["s1","s2","s3"]
    property int slideIndex: 1

    Canary {
        id: canary
        objectName: "canary"
        onCurrentAlarmChanged: console.log("Alarm changed")
        currentAlarm: 1
    }

    ContentManager {
        id: contentManager
    }

    function pushNextImg(){
        if(slideIndex>slideSources.length){
            slideIndex = 1
        }
        if(slideIndex%2!=0){
            oddSlide.source = "/slides/s"+slideIndex+".jpg"
            slides.clear()
            slides.push(oddSlide)
        }
        else{
            evenSlide.source = "/slides/s"+slideIndex+".jpg"
            slides.clear()
            slides.push(evenSlide)
        }
        slideIndex++
    }

    Image {
        id: oddSlide
        source: "/slides/s1.jpg"
        anchors.fill: parent
    }
    Image {
        id: evenSlide
        source: "/slides/s2.jpg"
        anchors.fill: parent
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
        onClicked: pushNextImg()//canary.currentAlarm = 3;
    }
    Rectangle {
        id: redRect
        color: "red"
        visible: true
    }
    Rectangle {
        id: blueRect
        color: "blue"
    }
    StackView {
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width*.8
        height: parent.height*.8
        id: slides
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
        initialItem: redRect
        onDepthChanged: {if(get(0)){
                console.log(get(0).source)
            }}
    }
}
