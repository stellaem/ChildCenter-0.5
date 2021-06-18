import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import "qrc:/QML/administration/timetableItem_func.js" as Func_items

Rectangle {
    id: _parent
    color: appearance.getColorBackground()
    ListView {
        id: _headerCabinet
        height: 40
        width: _gridVisible.width
        anchors.left: _headerTime.right
        anchors.right: _parent.right
        anchors.top: _parent.top
        orientation: Qt.Horizontal
        model: qMCabinet.rowCount()
        delegate:
            Rectangle {
            id: _itemHeaderCabinet
            width: _headerCabinet.width / qMCabinet.rowCount()
            height: _headerCabinet.height
            color: appearance.getColorBack()
            Text {
                anchors.fill: parent
                text: qMCabinet.data(qMCabinet.index(index, 1))
                font.pixelSize: 20
                color: appearance.getColorMain()
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }
    }
    ListView {
        id: _headerTime
        width: 100
        anchors.left: _parent.left
        anchors.top: _headerCabinet.bottom
        anchors.bottom: _parent.bottom
        model: settings.countHours()
        delegate:
            Rectangle {
            width: _headerTime.width
            height: _headerTime.height / settings.countCellPerHour()
            color: appearance.getColorBack()


            Rectangle {
                visible: index + 1  === settings.countHours() ? false : true
                height: 1
                color:  'cadetblue'
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
            }

            Text {
                anchors.fill: parent
                font.pixelSize: 20
                color: appearance.getColorMain()
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text:  settings.getListTime()[index * settings.countCellPerHour()].toLocaleTimeString("hh:mm")
            }
        }
    }
    GridLayout {
        id : _gridVisible
        anchors.left: _headerTime.right
        anchors.top: _headerCabinet.bottom
        anchors.bottom: _parent.bottom
        anchors.right: _parent.right
        flow : GridLayout.TopToBottom
        columnSpacing: 0
        rowSpacing: 0
        columns: qMCabinet.rowCount()
        rows: settings.countHours()
        Repeater {
            model: qMCabinet.rowCount() * settings.countHours()
            delegate:
                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color:Math.floor(index / settings.countHours())  % 2 ? "aliceblue" : "azure"
                    Rectangle {
                        visible: (index + 1) % settings.countHours()  ===  0 ? false : true
                        height: 1
                        color: "cadetblue"
                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }
            }

        }
    }
    GridLayout {
        id : _gridInvisible
        anchors.fill: _gridVisible
        flow : GridLayout.TopToBottom
        columnSpacing: 0
        rowSpacing: 0
        columns: qMCabinet.rowCount()
        rows: settings.countSegments()
        Repeater {
            model: qMCabinet.rowCount() * settings.countSegments()
            delegate:
                DropArea {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Rectangle {
                        anchors.fill: parent
                        opacity: 0
                    }
                }
        }
        Component.onCompleted: {
            Func_items.createItems()
        }
    }

    function reloadItems()
    {
        for (var i in _gridInvisible.data){
            if(_gridInvisible.data[i].typeName === '_itemClass')
            {

                _gridInvisible.data[i].destroy()
            }
        }
       Func_items.createItems()
    }

}
