import QtQuick 2.0

Rectangle {

    property string text:       "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
    property color  textColor:  alertMode ? "#394648" : "white"
    property int    textSize:   40
    property int    interval:   40
    property bool   alertMode:  false

    radius: 3
    color: Qt.rgba(1,1,1,.2)
    anchors.margins: 5
    clip: true

    Timer {
        id: timer
        interval: parent.interval; running: true; repeat: true
        onTriggered: moveTicker()
    }

    Timer {
        id: allClearTimer
        interval: 10000
        onTriggered: {
            allClearRect.width = 0
            timer.running=true
        }
    }

    Rectangle {
        id: canaryRect
        height: parent.height
        width: 0
        Behavior on width {
            NumberAnimation{duration: 1000; easing.type: Easing.OutCubic}
        }

        color: "#ddfff200"
        anchors.centerIn: parent
    }



    onAlertModeChanged: {
        if(!alertMode){
            canaryRect.visible=false
            canaryRect.width=0
            allClearRect.visible=true
            allClearRect.width=parent.width
            timer.running=false
            allClearTimer.running=true

        }
        else{
            canaryRect.visible=true
            canaryRect.width=parent.width
            allClearRect.visible=false
            allClearRect.width=0
        }
    }

    FontLoader{
        id: openSans
        source: "qrc:/fonts/os.ttf"
    }

    function longText(){
        var longText = ""
        for(var i = 0; i<10; i++){
            longText+=text+"    •    "
        }
        return longText //make the text super long
    }



    Text {
        id: tickerText
        x: parent.width //start on right edge
        height: parent.height
        text: {
            var longText = ""
            for(var i = 0; i<10; i++){
                longText+=parent.text+"    •    "
            }
            return longText //make the text super long
        }

        color: parent.textColor
        font.family: openSans.name
        font.pointSize: textSize
    }

    function moveTicker() {
        if(tickerText.x+tickerText.width < 0){
            tickerText.x = tickerText.parent.width;
        }
        tickerText.x -= 5;
    }

    Rectangle {
        id: allClearRect
        height: parent.height
        width: 0
        Behavior on width {
            NumberAnimation{duration: 1000; easing.type: Easing.OutCubic}
        }

        Text {
            id: allClearText
            text: "All clear"
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            font.family: openSans.name
            font.pointSize: textSize
            clip: true
            color: "white"
        }

        color: "#ff41CD52"
        anchors.centerIn: parent
    }

}
