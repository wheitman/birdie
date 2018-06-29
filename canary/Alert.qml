import QtQuick 2.5

Rectangle {
    id: page
    width: 960; height: 540
    color: "#f4f4f4"

    Rectangle {
        id: banner
        anchors.top: page.top; anchors.left: page.left; anchors.right: page.right
        height: (parent.height + parent.width) * .04
        color: "#ffe400"

        Image {
            id: bannerImg
            source: "res/banner.png"
            fillMode: Image.PreserveAspectFit
            height: parent.height
            mipmap: true
        }
    }

    Image {
        id: alertIcon
        source: "res/pause.svg"
        fillMode: Image.PreserveAspectFit
        anchors.top: banner.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: parent.height/10; anchors.bottomMargin: parent.height/10; anchors.leftMargin: parent.width/25
        height: parent.height-banner.height
        width: parent.width/2.5
        sourceSize.width: 600
        sourceSize.height: 600
    }

    Rectangle{
        id: messageArea
        anchors{ left: alertIcon.right; right: parent.right; top: banner.bottom; bottom: parent.bottom; rightMargin: parent.width/15; leftMargin: parent.width/20 }
        color: "transparent"

        Text {
            id: messageHeading
            text: "Sign-Out Paused"
            verticalAlignment: Text.AlignBottom
            anchors { top: parent.top; bottom: parent.verticalCenter; left: parent.left; right: parent.right; topMargin: parent.height/10 }
            font { family: "Segoe UI"; weight: Font.Bold }
            fontSizeMode: Text.Fit
            minimumPointSize: 24
            font.pointSize: 200
            wrapMode: Text.Wrap
        }

        Text {
            id: messageBody
            text: "until 2pm due to heavy rain."
            verticalAlignment: Text.AlignTop
            anchors { top: parent.verticalCenter; bottom: parent.bottom; left: parent.left; right: parent.right; bottomMargin: parent.height/4 }
            font { family: "Segoe UI" }
            fontSizeMode: Text.Fit
            minimumPointSize: 12
            font.pointSize: 200
            wrapMode: Text.Wrap
        }
    }
}
