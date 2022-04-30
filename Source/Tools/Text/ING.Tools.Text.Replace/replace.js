
const fs = require('fs');

const file_foreach = require('./utils/file_foreach');



const argv = process.argv;



function replace_file(file_path, srcKey, dstKey){

    let file_content = fs.readFileSync(file_path).toString();

    file_content = file_content.replaceAll(srcKey, dstKey);

    fs.writeFileSync(file_path, file_content);

}



function replace(){

    if(argv.length <= 4) {

        console.error(new Error('arguments not invalid'));

        return false;
    }

    console.log('star replacing');

    const item_path = argv[2];

    const srcKey = argv[3];

    const dstKey = argv[4];

    if(fs.statSync(item_path).isFile()){

        replace_file(item_path, srcKey, dstKey);

    }
    else{

        file_foreach(item_path, (item_path)=>{

            replace_file(item_path, srcKey, dstKey);

        });

    }

    return true;
}

if(!replace()) console.error(new Error('replace failed'));
else console.log('replace done');