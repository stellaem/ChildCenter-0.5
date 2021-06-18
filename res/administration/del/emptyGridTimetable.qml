import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


ListView {
    id: _parent
    property int hItem: 0
    Layout.fillHeight: true
    Layout.alignment: Qt.AlignCenter
    interactive: false
    delegate: Rectangle {
        id: _item
        width: _parent.width
        height: hItem
        color: "green"
        border.color: "black"

        MouseArea {
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            anchors.fill: parent
            hoverEnabled : true
            onClicked:(mouse)=> {
                if(mouse.button & Qt.RightButton)
                {

                    _item.color = "black"
                    _contextMenu.popup()
                }
                else
                {
                    console.log("leftClicked");
                }

            }
//            onDoubleClicked: console.log("DoubleClicked")
//            onEntered: { console.log("entered");  }


//            Connections {

//                function onDoubleClicked() {
//                    console.log("DoubleClicked");
//                }
//                function onEntered(){
//                    console.log("entered");
//                }
//            }
        }


    }
    Menu {
        id: _contextMenu
        width: 100
        MenuItem { text: "вырезать" }
        MenuItem { text: "Copy" }
        MenuItem { text: "Paste" }
    }
}
