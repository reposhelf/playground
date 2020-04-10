import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    color: "#42536d"
    width: 800
    height: 500
    title: qsTr("Naughts and Crosses")

    Loader {
        anchors.fill: parent
        source: "StartPage.qml"
    }
}
