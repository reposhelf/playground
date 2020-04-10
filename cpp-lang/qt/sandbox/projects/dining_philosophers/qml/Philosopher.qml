import QtQuick 2.0

Rectangle {
    id: root
    x: modelData.x
    y: modelData.y
    width: modelData.width
    height: modelData.height
    border.color: "black"
    color: "azure"

    Column {
        Image {
            source: "qrc:/images/close.png"
            width: 15
            height: 15
            x: root.width - width

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    controller.removePhilosopher(modelData.id)
                }
            }
        }

        Image {
            source: "qrc:/images/philosopher.png"
            width: 85
            height: 85
        }

        Rectangle {
            border.color: "black"
            height: 25
            width: root.width
            color: "transparent"

            Text {
                id: name
                text: modelData.philosopherName
                anchors.centerIn: parent
            }
        }

        Rectangle {
            height: 25
            width: root.width
            color: "transparent"

            Text {
                id: state
                text: modelData.philosopherStateString
                anchors.centerIn: parent
            }
        }
    }
}
