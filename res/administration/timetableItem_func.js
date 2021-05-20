function createItems()
{
        for (var cls = 0; cls < qMClasses.rowCount() ; cls++)
    {
        var typeName = "_itemClass"
        var idClass = qMClasses.data(qMClasses.index(cls, 0))
        var tStr = qMClasses.data(qMClasses.index(cls, 1))
        var time = new Date(1971, 3, 1, tStr.split(':')[0], tStr.split(':')[1])
        var cab = qMClasses.data(qMClasses.index(cls, 2))
        var indexCabinet = findIndexCabinet(cls)
        var specialist  = qMClasses.data(qMClasses.index(cls, 3))
        var duration = qMClasses.data(qMClasses.index(cls, 4))
        var type = qMClasses.data(qMClasses.index(cls, 5))
        var item = Qt.createComponent("qrc:/QML/administration/timetableGrid_Item.qml")
        item.createObject(_gridInvisible, {
            'typeName': typeName,
            'idClass': idClass,
            'time': time,
            'cabinet':  cab,
            'Layout.row': (time - settings.getStartCenter()) / (60000 * 60 / settings.countCellPerHour()),
            'Layout.column': indexCabinet,
            'Layout.rowSpan': settings.countCellPerHour() * duration / 60 ,
            'Layout.fillHeight': true,
            'Layout.fillWidth': true,
        })

    }
}

function findIndexCabinet(cls)
{
    for (var indexCabinet = 0; indexCabinet < qMCabinet.rowCount(); indexCabinet++)
    {
        if (qMCabinet.data(qMCabinet.index(indexCabinet, 0))  === qMClasses.data(qMClasses.index(cls, 2)))
        {
            return indexCabinet
        }
    }
}









