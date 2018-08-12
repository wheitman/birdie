import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import com.birdie.canary 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button {
        id: helloWorld
        text: "Hello, World!"
        objectName: "helloWorld"
    }
    Canary {
        currentAlarm: 1
    }
}
