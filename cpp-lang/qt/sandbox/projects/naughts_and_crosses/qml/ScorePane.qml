import QtQuick 2.0
import QtQuick.Layouts 1.2

Item {
    Connections {
        target: board
        onNewSignPlaced: {
            if (firstPlayerTurn.visible === true) {
                firstPlayerTurn.visible = false
                secondPlayerTurn.visible = true
            } else if (secondPlayerTurn.visible === true) {
                secondPlayerTurn.visible = false
                firstPlayerTurn.visible = true
            }
        }
        onResetted: {
            firstPlayerTurn.visible = true
            secondPlayerTurn.visible = false
        }
    }

    ColumnLayout {
        anchors.fill: parent

        Item {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: firstPlayerTurn
                source: "qrc:/images/green-circle-th.png"
                width: 24
                height: 24
                visible: true
            }

            ColumnLayout {
                anchors.fill: parent

                Image {
                    Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    Layout.maximumWidth: 75
                    Layout.maximumHeight: 75
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    source: "qrc:/images/player1.png"
                }

                Text {
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    font.pixelSize: 24
                    color: "#bac3d1"
                    text: result.firstPlayerName
                }

                Text {
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    font.pixelSize: 30
                    font.bold: true
                    color: "#d6a42f"
                    text: result.firstPlayerScore
                }
            }
        }

        Rectangle {
            color: "red"
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.maximumHeight: 2
            Layout.maximumWidth: 400
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Item {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: secondPlayerTurn
                source: "qrc:/images/green-circle-th.png"
                width: 24
                height: 24
                visible: false
            }

            ColumnLayout {
                anchors.fill: parent

                Image {
                    Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                    Layout.maximumWidth: 75
                    Layout.maximumHeight: 75
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    source: "qrc:/images/player2.png"
                }

                Text {
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    font.pixelSize: 24
                    color: "#bac3d1"
                    text: result.secondPlayerName
                }

                Text {
                    Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
                    font.pixelSize: 30
                    font.bold: true
                    color: "#d6a42f"
                    text: result.secondPlayerScore
                }
            }
        }
    }
}
