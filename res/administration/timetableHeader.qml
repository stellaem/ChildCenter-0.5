import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item{
    id: _parent
    RowLayout {
        id: _header
        Rectangle{
            id: _title
        }

        Button {
            id: _bottonAdd
            text: "Add"
            onClicked: console.log('add')
        }

        TextField {
            id: _searchClasses
        }

        ComboBox{
            id: _selectRange
        }

    }
}


