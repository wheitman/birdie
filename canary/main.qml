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

    Rectangle {
        id: messageBox
        anchors.left: alertIcon.right; anchors.right: parent.right; anchors.top: banner.bottom; anchors.bottom: parent.bottom
        color: "transparent"
        Text {
            id: messageHeading
            text: "SIGN-OUT HAS BEEN PAUSED"
            fontSizeMode: Text.Fit
            minimumPointSize: 24
            width: parent.width
            wrapMode: Text.Wrap
            font.pointSize: 200
            anchors.bottom: messageBody.top; anchors.top: parent.top; anchors.right: parent.right; anchors.left: parent.left
            font { family: "Segoe UI"; bold: true }
            anchors.rightMargin: 25; anchors.leftMargin: 25
        }
        Text {
            id: messageBody
            text: "until 2pm due to heavy rain."
            anchors.bottom: parent.bottom
            fontSizeMode: Text.Fit
            minimumPointSize: messageHeading.minimumPointSize/2
        }
    }
}
