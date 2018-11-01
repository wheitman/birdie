import QtQuick 2.0

Item {

    anchors.margins: 5
    property var eventArray

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

    function updateList(){
        for(var i = 0; i<eventArray.length; i++){
            eventList.model.append({title: eventArray[i].title, time: eventArray[i].time, planner: eventArray[i].planner, location: eventArray[i].location, description: eventArray[i].description})
            console.log("Appending: "+eventArray[i].title)
        }
    }

    ListView{
        id: eventList
        anchors.top: titleBox.bottom
        anchors.bottom: mainBox.bottom
        anchors.left: mainBox.left
        anchors.right: mainBox.right
        anchors.margins: 8
        spacing: 5
        model: EventModel {}
        delegate: EventCard {
            title: model.title
            time: model.time
            planner: model.planner
            location: model.location
            description: model.description
            width: parent.width
        }
    }

//    Text {
//        id: mainText
//        anchors.top: titleBox.bottom
//        anchors.bottom: mainBox.bottom
//        anchors.left: mainBox.left
//        anchors.right: mainBox.right
//        text: eventArray[0].title
//        color: "white"
//        font.family: openSans.name
//        anchors.margins: 5
//    }

}
