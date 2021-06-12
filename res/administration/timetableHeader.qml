import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Rectangle {
    id: _parent
    color: appearance.getColorBackground()

    // ЗАГОЛОВОК РАСПИСАНИЕ
    RowLayout{
        anchors.left: _parent.left
        anchors.verticalCenter: _parent.verticalCenter
        id: _title
        Rectangle{
            width: 50
            Image {
                width: 25
                height: 25
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:/QML/administration/menu.png"
            }
        }
        Text {
            text: qsTr("Timetable")
            font.pixelSize: 20
            color: appearance.getColorMain()
        }
    }

    // КНОПКА ДОБАВИТЬ
    Button {
        id: _bottonAdd
        onClicked: console.log(qsTr("Add"))
        width: 100
        implicitHeight: 35
        anchors.left: _title.right
        anchors.leftMargin: 10
        anchors.verticalCenter: _parent.verticalCenter
        background:
            Rectangle {
                anchors.fill: _bottonAdd
                color: appearance.getColorBack()
                border.color: _bottonAdd.down ? appearance.getColorBorder() : appearance.getColorBorder()
                border.width: 1
                radius: 2
            }
        contentItem:
            Text {
                text: qsTr("Add")
                font.pixelSize: 20
                color: _bottonAdd.down ? appearance.getColorMain() : appearance.getColorMain()
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
    }

    // ПОЛЕ ПОИСКА
    TextField {
        id: _searchClasses
        anchors.right:_parent.right
        anchors.leftMargin: 10
        anchors.left: _bottonAdd.right
        implicitHeight: 35
        anchors.verticalCenter: _parent.verticalCenter
        color : appearance.getColorMain()
        font.pixelSize: 20
        verticalAlignment : TextInput.AlignVCenter
        anchors.rightMargin: 10
        background:
            Rectangle {
                anchors.fill: _searchClasses
                color: appearance.getColorBack()
                border.color: appearance.getColorBorder()
                border.width: 1
                radius: 2
                Image {
                    width: 25
                    height: 25
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    source: "qrc:/QML/administration/search.png"
                    anchors.rightMargin: 5
                }
            }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
