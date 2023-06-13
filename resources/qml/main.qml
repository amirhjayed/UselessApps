/*
* Copyleft (l) Useless NV. All rights dispensed.
* Free and for useless use only. The contents of this document consitutes shared
* information of Useless Group of companies. If you use this in a useful way, you dissapoint me.
* Author: hajayedamir@gmail.com
*/

import QtQuick

Window
{
    width: 240
    height: 240
    visible: true
    title: qsTr("UselessApps")

    Text
    {
        id: open_counter
        text: uselessStats.opened_count
        font.family: "Helvetica"
        font.pointSize: 30
        font.bold: true
        color: "red"

        anchors.centerIn: parent
    }
}
