import QtQuick 2.0

Rectangle {
    id: root
    color: "#383a4c"
    height: 85
    property string philName: ""

    Item {
        anchors.top: parent.top
        height: parent.height * 0.5
        width: parent.width

        Rectangle {
            anchors.centerIn: parent
            color: "#d7d8e0"
            width: 200
            height: 20

            TextInput {
                id: input
                anchors.fill: parent
                onTextChanged: {
                    philName = text
                }
            }
        }
    }

    Item {
        anchors.bottom: parent.bottom
        height: parent.height * 0.5
        width: parent.width

        Rectangle {
            anchors.centerIn: parent
            color: "#56c41f"
            width: 100
            height: 25

            Text {
                anchors.centerIn: parent
                text: "Add Philosopher"
                font.pixelSize: 12
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    controller.addPhilosopher(philName)
                    input.text = ""
                }
            }
        }
    }
}
