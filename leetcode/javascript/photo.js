const fs = require('fs');
const path = require('path');
const process = require('process');
const folderName = process.argv[2];
const folderPath = path.join(__dirname, folderName);

function isModified(imgName) {
    var modifiedName = "IMG_E" + imgName.split("_")[1];
    return fs.existsSync(folderPath + "/" + modifiedName +".jpg");
};

function moveFile(folderName, fileName) {
    var newFolderPath = folderPath + "/" + folderName;

    if (!fs.existsSync(newFolderPath)) {
        fs.mkdirSync(newFolderPath);
    }

    fs.promises.rename(folderPath + "/" + fileName, newFolderPath + "/" + fileName)
    .then(()=>{console.log('move ' + fileName + ' to ' + folderName)})
    .catch(console.error);
};

fs.readdir(folderPath, "utf8", function(err, files) {
    if (err) throw err;

    console.log('Processing in ' + folderPath + '...');

    files.forEach(function(filename) {
        var splitStr = filename.split(".");

        if (splitStr[1] == 'mp4' || splitStr[1] == 'mov') {
            moveFile("video", filename);
        } else if (splitStr[1] == 'png' || splitStr[1] == 'aae') {
            moveFile("captured", filename);
        } else if (splitStr[1] == 'jpg' && isModified(splitStr[0])) {
            moveFile("duplicated", filename);
        }
    });

});


