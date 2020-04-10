import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    color: "#405068"
    width: 720
    height: 870

    Workspace {}

    ToolBar {
        id: toolBar
        anchors.bottom: parent.bottom
        width: parent.width
    }
}
