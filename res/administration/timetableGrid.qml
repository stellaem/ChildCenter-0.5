import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "qrc:/QML/administration/timetableItem_func.js" as Func_items

Item {
    readonly property int wItem: 300
    readonly property int hItem: 5
    readonly property int hTable: hItem * settings.getListTime().size
    id: _parent
    ListView {
        id: _headerCabinet
        height: 40
        width: _gridVisible.width
        anchors.left: _headerTime.right
        anchors.top: _parent.top
        orientation: Qt.Horizontal
        model: listVCabinet.length
        delegate:
            Rectangle {
            width: wItem
            height: _headerCabinet.height
            color: '#F3F5F8'
            Text {
                anchors.fill: parent
                text: listVCabinet[index].name
                font.pixelSize: 20
                color: '#617388'
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
            height: hItem * settings.getCellPerHour()
            color: '#F3F5F8'


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
                font.pixelSize: 16
                color: '#617388'

                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text:  settings.getListTime()[index * settings.getCellPerHour()].toLocaleTimeString("hh:mm")
            }

        }
    }
    GridLayout {
        id : _gridVisible
        anchors.left: _headerTime.right
        anchors.top: _headerCabinet.bottom
        flow : GridLayout.TopToBottom
        columnSpacing: 0
        rowSpacing: 0
        columns: listVCabinet.length
        rows: settings.countHours()
        Repeater {
            model: listVCabinet.length * settings.countHours()
            delegate:
                Rectangle {
                width: wItem
                height: hItem * settings.getCellPerHour()
                color:Math.floor(index / settings.countHours())  % 2 ? "aliceblue" : "azure"
                Rectangle {
                visible: (index + 1) % settings.countHours()  ===  0 ? false : true
                height: 1
                color: 'cadetblue'
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                }
            }

        }
    }
    Item {
        id : _gridInvisible
        anchors.fill: _gridVisible
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
