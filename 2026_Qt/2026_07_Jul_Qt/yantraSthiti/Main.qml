import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {

    id: root

    visible: true

    width: 1200
    height: 750

    minimumWidth: 360
    minimumHeight: 600

    title: "YantraSthiti"

    color: "#101318"

    ScrollView {

        anchors.fill: parent

        clip: true

        ScrollBar.vertical.policy: ScrollBar.AsNeeded
        contentWidth: availableWidth

       // Item {

         //   width: root.width
          //  height: mainLayout.height + 48
        //-------------------------------------------
        // Main layout
        //-------------------------------------------

        ColumnLayout {
            id: mainLayout
/*
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top

            anchors.leftMargin: 24
            anchors.rightMargin: 24
            anchors.topMargin: 24
*/
            width: parent.width - 48
            x: 24
            y: 24

            spacing: 20

            //-------------------------------------------
            // Header
            //-------------------------------------------

            RowLayout {

                Layout.fillWidth: true

                Label {
                    text: "YantraSthiti"

                    color: "white"

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

            ColumnLayout {

                Layout.fillWidth: true

                spacing: 8

                Label {
                    text: "Server"

                    color: "#8f98a8"

                    font.pixelSize: 14
                }

                ComboBox {

                    id: serverComboBox

                    Layout.fillWidth: true

                    model: [
                        "Ei Labs Server_01",
                        "Ei Labs Server_02",
                        "Ei Labs Server_03"
                        ]

                            currentIndex: 0

                            font.pixelSize: 16
                        }
            }

        //-------------------------------------------
        // Server information
        //-------------------------------------------

        ColumnLayout {

            Layout.fillWidth: true

            spacing: 4

            Label {

                text: database.serverName

                color: "white"

                font.pixelSize: 24
                font.bold: true
            }

            Label {

                text: database.ip

                color: "#8f98a8"

                font.pixelSize: 15
            }
        }

        //-------------------------------------------
        // Metrics
        //-------------------------------------------

        GridLayout {

            id: metricsLayout

            Layout.fillWidth: true

            columns: root.width >= 700 ? 3 : 1

            rowSpacing: 12
            columnSpacing: 12

            MetricCard {
                title: "CPU"
                metricValue: database.cpu

                Layout.fillWidth: true
                Layout.preferredHeight: 140
            }

            MetricCard {
                title: "RAM"
                metricValue: database.ram

                Layout.fillWidth: true
                Layout.preferredHeight: 140
            }

            MetricCard {
                title: "DISK"
                metricValue: database.disk

                Layout.fillWidth: true
                Layout.preferredHeight: 140
            }
        }

        //-------------------------------------------
        // CPU graph
        //-------------------------------------------

        MetricGraph {

            Layout.fillWidth: true
            Layout.preferredHeight: 220

            title: "CPU Usage"
        }

        //-------------------------------------------
        // RAM graph
        //-------------------------------------------

        MetricGraph {

               Layout.fillWidth: true
               Layout.preferredHeight: 220

               title: "RAM Usage"
           }
    }
        }
}


