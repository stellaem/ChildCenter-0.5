import QtQuick
import QtQuick.Controls

Item{
    id: item1
    ComboBox {
        id: _selectPeriod
        model: ["First", "Second", "Third"]
        height: 35
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right

        background:
            Rectangle {
                color: '#F3F5F8'
                border.color: '#617388'
                border.width: 1
                radius: 2
                Image {
                    width: 25
                    height: 25
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    source: "qrc:/QML/administration/calendar.png"
                    anchors.leftMargin: 5
                }
            }
        delegate: ItemDelegate {
             width: _selectPeriod.width
             highlighted: _selectPeriod.highlightedIndex === index
             contentItem:
                 Text {
                     text: modelData
                     color: "#21be2b"
                     font: _selectPeriod.font
                     elide: Text.ElideRight
                     verticalAlignment: Text.AlignVCenter
                }
        }
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
