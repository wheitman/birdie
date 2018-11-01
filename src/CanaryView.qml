import QtQuick 2.0

Rectangle {

    color: "#fff200"
    anchors.fill: parent
    property string title: "Emergency Alert"

    onVisibleChanged: {
        console.log("YEET")
        if(visible){
            opacity=1
        }
        else{
            opacity=0
        }
    }

    Behavior on opacity{
        NumberAnimation{
            duration: 1000
            easing.type: Easing.OutCubic
        }
    }

    FontLoader{
        id: openSans
        source: "qrc:/fonts/os.ttf"
    }

    Rectangle {
        id: titleRect
        color: "#394648"
        height: parent.height/4.3
        anchors.top: parent.top
        width: parent.width

        Text{
            text: title.toUpperCase()
            color: "#fff200"
            anchors.fill: parent
            minimumPixelSize: 20
            font.pointSize: 200
            fontSizeMode: Text.Fit
        }
    }

}
