
const fs = require('fs');



const argv = process.argv;



function build(){

    if(argv.length <= 2) {

        console.error(new Error('documentation build tool cant build without build mode'));

        return false;
    }

    const mode_name = argv[2];

    const mode_module_path = `./modes/${mode_name}.js`;

    if(fs.existsSync(mode_module_path)) {

        console.log(`use ${mode_name} mode`);

        const mode = require(mode_module_path);

        return mode.build(argv);

    }
    else {
        
        console.error(new Error(`${mode_name} mode not found`));

    }

}

if(!build()) console.error(new Error('build failed'));
else console.log('build done');