import QtQuick 2.0

Rectangle {
    property var sources: null
    property string slideDir: null
    property int sourceIndex: 2
    property int fadeDuration: 500 //ms

    function nextSlide(){
        state = state=="fadeInAltSlide" ? "fadeOutAltSlide" : "fadeInAltSlide" //change to other image
    }

    function pushSources(){
        if(sourceIndex===sources.length){sourceIndex=0} //loop around
        if(slideA.opacity===0){ //if slideB is currently shown
            slideA.source=slideDir+"/"+sources[sourceIndex]
        }
        else{ //if slideA is currently shown
            slideB.source=slideDir+"/"+sources[sourceIndex]
        }

        sourceIndex++
    }

    states: [
        State {
            name: "fadeInAltSlide"
            PropertyChanges{target: slideA; opacity: 0}
            PropertyChanges{target: slideB; opacity: 1}
        },
        State {
            name: "fadeOutAltSlide"
            PropertyChanges{target: slideA; opacity: 1}
            PropertyChanges{target: slideB; opacity: 0}
        }
    ]

    transitions: [
        Transition {
            id: fadeTransition
            SequentialAnimation{
                NumberAnimation {
                    id: fadeAnimation
                    property: "opacity";
                    easing.type: Easing.InOutQuad;
                    duration: fadeDuration
                }
                ScriptAction{
                    script: pushSources()
                }
            }
        }
    ]

    Image {
        anchors.fill: parent
        id: slideA
        source: slideDir+"/"+sources[0]
        asynchronous: true
    }
    Image {
        anchors.fill: parent
        id: slideB
        source: slideDir+"/"+sources[1]
        opacity: 0 //start hidden
        asynchronous: true
    }

    state: "FadeOutAltSlide" //start witht the alternate (second) slide hidden
}
