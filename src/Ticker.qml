import QtQuick 2.0

Rectangle {

    property string text:       "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
    property color  textColor:  "white"
    property int    textSize:   40
    property int    interval:   40

    radius: 3
    color: Qt.rgba(1,1,1,.2)
    anchors.margins: 5
    clip: true

    Timer {
        id: timer
        interval: parent.interval; running: true; repeat: true
        onTriggered: moveTicker()
    }

    FontLoader{
        id: openSans
        source: "qrc:/fonts/os.ttf"
    }

    Text {
        id: tickerText
        x: parent.width //start on right edge
        height: parent.height
        text: parent.text
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

}
