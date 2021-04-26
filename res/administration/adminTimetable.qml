import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 2
import Timetable 1.0


Item {
    readonly property int wItem: 200
    readonly property int hItem: settings.minInSegment()
    readonly property int hTable: hItem * settings.getListTime().size
    id: _parent
    ListView {
        id: _timeHeader
        width: 30
        anchors.left: _parent.left
        anchors.top: _parent.top
        anchors.bottom: _parent.bottom
        model: settings.getListTime()
        delegate: Rectangle {
            width: _timeHeader.width
            height: hItem
            border.width: 1
            Text {
                font.pixelSize: index % 4 == 0 ? 12 : 10
                text:  settings.getListTime()[index].toLocaleTimeString("hh:mm")
            }

        }
    }
    //    RowLayout {
    //        id: _layoutGrid
    //        anchors.left: _timeHeader.right
    //        anchors.top: _parent.top
    //        anchors.bottom: parent.bottom
    //        spacing: 0

    //        Component.onCompleted:
    //        {
    //            listVCabinet.forEach(function(cabinet, i, arr){
    //                var сomp = Qt.createComponent("qrc:/QML/administration/emptyGridTimetable.qml");
    //                сomp.createObject(_layoutGrid, {'model': settings.countSegments(),
    //                                                'width': wItem,
    //                                                'hItem': hItem
    //                                                });
    //            });
    //        }
    //    }
    GridLayout {
        id : grid
        anchors.left: _timeHeader.right
        anchors.top: _parent.top
//        anchors.bottom: _parent.bottom
//        anchors.right: _parent.right
        columnSpacing: 0
        rowSpacing: 0
        columns: 2
        rows: 48 * 2
        Repeater {
            model: 48 * 2
            delegate: Rectangle {
                width: wItem
                height: hItem
                color: "green"
                border.color: "black"


            }
        }
        Rectangle{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 1
            Layout.column: 1
            Layout.rowSpan: 4
            color: "green"
        }

    }

//    Component.onCompleted:
//    {
//        createItems()
//    }

//    function reloadItem()
//    {
//        for (var i in _parent.data){
//            if(_parent.data[i].typeName === 'itemClass')
//            {
//                _parent.data[i].destroy()
//            }
//        }
//        createItems()
//    }

//    function createItems()
//    {
//        listVCabinet.forEach(function(cabinet, i, arrC)
//        {

//            var model = mapModelsClasses[cabinet.getId()]

//            for (i = 0; i < model.rowCount() ; i++)
//            {
//                var typeName = "itemClass"
//                var idClass = model.data(model.index(i, 0))
//                var tStr = model.data(model.index(i, 1))
//                var time = new Date(1971, 3, 1, tStr.split(':')[0], tStr.split(':')[1])
//                var cab = model.data(model.index(i, 2))
//                var specialist  = model.data(model.index(i, 3))
//                var duration = model.data(model.index(i, 4))
//                var type = model.data(model.index(i, 5))
//                var item = Qt.createComponent("qrc:/QML/administration/itemTimetable.qml");
//                item.createObject(_parent, {
//                                      'typeName': typeName,
//                                      'idClass': idClass,
//                                      'duration': duration,
//                                      'time': time,
//                                      'cabinet':  cab,
//                                      'width': wItem,
//                                      'x': wItem * (cab - 1) + _timeHeader.width,
//                                      // BUG при других значениях количества сигментов в часе, нужно составлять более универсальную формулу
//                                      'y': (time - settings.getStartCenter()) / 60000  // 60000 миллисекунд в минуте
//                                  })
//            }

//        });
//    }

}


