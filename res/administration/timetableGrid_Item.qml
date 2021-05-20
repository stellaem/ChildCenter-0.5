import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: _parent
    property string typeName: ""
    property int idClass: 0
    property date time: new Date()
    property int cabinet: 0
    property int specialist: 0
    property int type: 0

    MouseArea {
        id: _mouseArea
        anchors.fill: _parent
        drag.target: _clsTile
        onReleased: parent = _clsTile.Drag.target !== null ? _clsTile.Drag.target : _parent

        Rectangle {
           id: _clsTile
           width: _parent.width
           height: _parent.height
           color: "blue"
           border.width: 1
           radius: 10
           Drag.active: _mouseArea.drag.active
           Drag.hotSpot.x: width / 2
           states: State {
               when: _mouseArea.drag.active
               ParentChange { target: _clsTile; parent: _parent }
               AnchorChanges { target: _clsTile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
           }

        }
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        hoverEnabled : true
        onClicked: (mouse) => {
            if(mouse.button & Qt.RightButton)
            {
                _contextMenu.popup()
            }
            else
            {
                console.log("leftClicked");
            }
        }
    }
    Menu {
        id: _contextMenu
        width: 100
        MenuItem { text: "Cut" }
        MenuItem { text: "Copy" }
        MenuItem { text: "Paste" }
    }
 }


