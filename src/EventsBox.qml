import QtQuick 2.0

Item {

    anchors.margins: 5

    Rectangle {
        anchors.top: parent.top
        width: parent.width
        height: parent.height*.07
        id: titleBox
        radius: 3
        color: "white"
        opacity: .8
    }

    FontLoader{
        id: openSans
        source: "qrc:/fonts/os.ttf"
    }

    Text {
        anchors.fill: titleBox
        text: "Upcoming Events"
        anchors.margins: 5
        font.pointSize: 100
        minimumPointSize: 10
        horizontalAlignment: Text.AlignHCenter
        //color: "white"
        fontSizeMode: Text.Fit
        font.family: openSans.name
        font.weight: Font.DemiBold
    }

    Rectangle {
        id: mainBox
        anchors.top: titleBox.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        color: "transparent"
        border.color: "white"
        border.width: 3
        opacity: .2
        radius: 3
    }

    Text {
        id: mainText
        anchors.top: titleBox.bottom
        anchors.bottom: mainBox.bottom
        anchors.left: mainBox.left
        anchors.right: mainBox.right
        text: "Lorem ipsum dolor sit amet"
        color: "white"
        font.family: openSans.name
        anchors.margins: 5
    }

}
