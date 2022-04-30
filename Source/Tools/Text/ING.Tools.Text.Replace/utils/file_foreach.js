
const fs = require('fs');



var file_foreach = function(directory, callback){

    fs.readdirSync(directory).forEach(item => {

        let item_path = directory + '/' + item;
        
        if(fs.statSync(item_path).isFile()){

            callback(item_path);

        }
        else{

            file_foreach(item_path, callback);

        }

    });

}



module.exports = file_foreach;