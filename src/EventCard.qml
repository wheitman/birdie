import QtQuick 2.0

Item {

    property string time;
    property string title;
    property string planner;
    property string location;
    property string description;

    height: eventText.contentHeight+eventTitle.height+10

    Rectangle {
        color: "white"
        opacity: .2
        anchors.fill: parent
        radius: 3
    }

    Text {
        id: eventTitle
        color: "white"
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        text: "<strong>"+title+"</strong>"
        anchors.leftMargin: 3
        anchors.topMargin: 5
        wrapMode: Text.Wrap
        font.pointSize: 12
    }

    Text {
        id: eventText
        color: "white"
        anchors.top: eventTitle.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        text: "<i>"+time+"</i> | <i>"+location+"</i><br/>"+description
        anchors.leftMargin: 3
        wrapMode: Text.Wrap
    }

}
