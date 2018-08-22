import QtQuick 2.7

Item
{

    property date date

    Timer {
        id: clockTimer
        interval: 500; running: true; repeat: true //check every .5 seconds
        onTriggered: date = new Date;
    }

    FontLoader{
        id: openSans
        source: "qrc:/fonts/os.ttf"
    }

    onDateChanged: {
        dateText.text = date.toLocaleDateString()
        timeText.text = Qt.formatDateTime(date, "h:mm ap")
    }

    Text {
        id: dateText
        text: "Saturday, January 1"
        height: parent.height*.4
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.left: parent.left
        color: "white"
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignRight
        minimumPointSize: 10
        font.pointSize: 40
        fontSizeMode: Text.Fit
        padding: 0
        font.family: openSans.name
        font.italic: true
        font.weight: Font.Light
    }

    Text {
        id: timeText
        text: "8:10 am"
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        height: parent.height * 3/4
        color: "white"
        minimumPointSize: 10
        font.pointSize: 60
        fontSizeMode: Text.Fit
        verticalAlignment: Text.AlignBottom
        horizontalAlignment: Text.AlignRight
        padding: 0
        font.family: openSans.name
    }

}
