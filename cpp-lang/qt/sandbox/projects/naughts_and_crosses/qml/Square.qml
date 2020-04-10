import QtQuick 2.0

Rectangle {
    x: modelData.x
    y: modelData.y
    z: modelData.z
    width: modelData.width
    height: modelData.height
    color: "#e1e3e8"

    MouseArea {
        anchors.fill: parent
        onClicked: modelData.clicked()
    }

    Image {
        anchors.fill: parent
        anchors.margins: 15
        source: modelData.imageSource
    }
}
