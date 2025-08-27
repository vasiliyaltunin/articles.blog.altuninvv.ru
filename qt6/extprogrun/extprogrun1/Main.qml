import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Button {
            width: 60
            height: 30

            anchors.horizontalCenter: parent.horizontalCenter

            text: "Start"

            onClicked: {
               console.log("Clicked")
            }
        }

        BusyIndicator {
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
