import QtQuick 2.0

Rectangle {

    property string text:       "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
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
        text: parent.text
        color: parent.textColor
        font.pointSize: parent.textSize
        font.family: openSans.name
    }

    function moveTicker() {
        if(tickerText.x+tickerText.width < 0){
            tickerText.x = tickerText.parent.width;
        }
        tickerText.x -= 3;
        console.log(tickerText.x)
    }

}
