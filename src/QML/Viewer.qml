import QtQuick 2.15
import QtQuick.Controls 6.2
import Qt.labs.platform 1.1

Item {
    function log(...msg) {
        let msgs = "";
        msg.forEach((item) => {
                        if (msgs.length != 0) {
                            msgs += " ";
                        }
                        msgs += item;
                    });
        console.log(msgs);
    }

    FileDialog {
        id: fileDialog
        objectName: "fileDialog"
        currentFile: selectedFileTextArea.text

        onFileChanged: {
            log(objectName + ".file =", file.toString().slice(8));
            fileMgrInstance.run(file.toString().slice(8));
        }
    }

    Label {
        id: fileLable
        x: 292
        y: 26
        text: qsTr("文件：")
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 14
    }

    TextField {
        id: selectedFileTextArea
        x: 70
        y: 70
        width: 500
        objectName: "selectedFileTextArea"
        text: fileDialog.file.toString().slice(8)
        font.pointSize: 12
        placeholderText: qsTr("选择文件")
    }

    Button {
        id: selectFileButton
        x: 268
        y: 124
        width: 105
        height: 54
        text: qsTr("选择")
        font.pointSize: 10

        onClicked: {
            log(text, "clicked");
            fileDialog.open();
        }
    }
}
