import QtQuick 2.0
import QtQuick.Layouts 1.2

Item {
    Loader {
        id: loader
        anchors.fill: parent
    }

    ColumnLayout {
        id: layout
        anchors.fill: parent

        // text input 'Second Player'
        Rectangle {
            color: "#bac3d1"
            Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 100
            Layout.maximumWidth: 300
            Layout.minimumHeight: 30
            Layout.preferredHeight: 30
            Layout.maximumHeight: 30
            TextInput {
                id: firstPlayerName
                anchors.fill: parent
                font.pixelSize: 24
                text: "First Player"
            }
        }

        // text input 'First Player'
        Rectangle {
            color: "#bac3d1"
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 100
            Layout.maximumWidth: 300
            Layout.minimumHeight: 30
            Layout.preferredHeight: 30
            Layout.maximumHeight: 30
            TextInput {
                id: secondPlayerName
                anchors.fill: parent
                font.pixelSize: 24
                text: "Second Player"
            }
        }

        // button 'Next'
        Rectangle {
            color: "green"
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            Layout.minimumWidth: 100
            Layout.preferredWidth: 100
            Layout.maximumWidth: 100
            Layout.minimumHeight: 40
            Layout.preferredHeight: 40
            Layout.maximumHeight: 40
            Text {
                anchors.centerIn: parent
                color: "#bac3d1"
                text: "Next"
                font.pixelSize: 24
            }
            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    result.firstPlayerName = firstPlayerName.text
                    result.secondPlayerName = secondPlayerName.text
                    loader.source = "BattlePage.qml"

                    layout.visible = false
                }
            }
        }
    }
}
