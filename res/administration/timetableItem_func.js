function createItems()
{
    listVCabinet.forEach(function(cabinet, i, arrC)
    {
        var model = mapModelsClasses[cabinet.getId()]
            for (var cls = 0; cls < model.rowCount() ; cls++)
        {
            var typeName = "_itemClass"
            var idClass = model.data(model.index(cls, 0))
            var tStr = model.data(model.index(cls, 1))
            var time = new Date(1971, 3, 1, tStr.split(':')[0], tStr.split(':')[1])
            var cab = model.data(model.index(cls, 2))
            var specialist  = model.data(model.index(cls, 3))
            var duration = model.data(model.index(cls, 4))
            var type = model.data(model.index(cls, 5))
            var item = Qt.createComponent("qrc:/QML/administration/timetableGrid_Item.qml");
            item.createObject(_gridInvisible, {
              'typeName': typeName,
              'idClass': idClass,
              'time': time,
              'cabinet':  cab,
              'width': wItem,
              'height': duration,
              'x': wItem * i,
              'y': (time - settings.getStartCenter()) / 60000,
            })
        }

    });
}

