import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 1200
    height: 750

    visible: true

    title: "YantraSthiti"

    color: "#101318"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 24
        spacing: 20

        //-------------------------------------------
        // Header
        //-------------------------------------------

        RowLayout {
            Layout.fillWidth: true

            Label {
                text: "YantraSthiti"

                color: "green"
                font.pixelSize: 30
                font.bold: true
            }

            Item {
                Layout.fillWidth: true
            }

            Label {
                text: "● Connected"

                color: "#55d68a"
                font.pixelSize: 16
            }
        }

        //-------------------------------------------
        // Server selector
        //-------------------------------------------

        RowLayout {
            Layout.fillWidth: true

            Label {
                text: "Server"

                color: "#b8bec9"
                font.pixelSize: 16
            }

            ComboBox {
                id: serverComboBox

                Layout.preferredWidth: 350

                model: [
                    "Ei Labs Server_01",
                    "Ei Labs Server_02",
                    "Ei Labs Server_03"
                ]

                currentIndex: 0
            }

            Item {
                Layout.fillWidth: true
            }
        }

        //-------------------------------------------
        // Server information
        //-------------------------------------------

        ColumnLayout {
            Layout.fillWidth: true
            spacing: 4

            Label {
                text: serverComboBox.currentText

                color: "white"
                font.pixelSize: 24
                font.bold: true
            }

            Label {
                text: "192.168.0.124"

                color: "#8f98a8"
                font.pixelSize: 15
            }
        }

        //-------------------------------------------
        // Metrics
        //-------------------------------------------

        RowLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: 150

            MetricCard {
                title: "CPU"
                value: "23 %"

                Layout.fillWidth: true
            }

            MetricCard {
                title: "RAM"
                value: "47 %"

                Layout.fillWidth: true
            }

            MetricCard {
                title: "DISK"
                value: "61 %"

                Layout.fillWidth: true
            }
        }

        //-------------------------------------------
        // Graph area
        //-------------------------------------------

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "#181c23"
            radius: 12

            Label {
                anchors.centerIn: parent

                text: "Graphs will come here"

                color: "#697180"
                font.pixelSize: 20
            }
        }
    }
}

