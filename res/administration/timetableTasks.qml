import QtQuick


Rectangle {
    id: _parent
    color: appearance.getColorBack()
    Rectangle{
        id: _header
        anchors.left: _parent.left
        anchors.right: _parent.right
        anchors.top: _parent.top
        color: appearance.getColorBack()
        height: 50
        Text {
            anchors.fill: _header
            font.pixelSize: 20
            color: appearance.getColorMain()
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Day's tasks")
        }
    }
    ListView {
        id: _listViewTask
        anchors.top: _header.bottom
        anchors.bottom: _parent.bottom
        anchors.right: _parent.right
        anchors.left: _parent.left
        model: tableModelTask
        delegate: Rectangle {
                width: _listViewTask.width - 5
                height: _textTask.height
                color: appearance.getColorBackground()
                border.color: appearance.getColorBorder()
                Row {
                    Rectangle {
                        color: appearance.getColorBack()
                        border.color: appearance.getColorBorder()
                        height: 8
                        width: 8
                    }
                    Text {
                        id: _textTask
                        text: tableModelTask.data(tableModelTask.index(index, 8))
                        width: _listViewTask.width - 25
                        font.pixelSize: 12
                        color: appearance.getColorMain()
                        wrapMode: Text.WordWrap
                    }
                }
                }
        spacing: 2

    }
}
