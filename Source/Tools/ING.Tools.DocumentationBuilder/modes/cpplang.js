
const file_foreach = require('../utils/file_foreach.js');
const is_json_file = require('../utils/is_json_file.js');

const path = require('path');
const fs = require('fs');



module.exports = new (class {

    constructor(){



    }

    clear(){

        this.projects = new Object();
        this.cpp_objects = new Object();

        this.cpp_obj_paths = [];
        this.project_paths = [];

    }

    get_project_path(project_name){

        let normalized_project_name = '';

        for(let i of project_name){

            if(i == ' ') continue;

            if (i == '\\') {

                normalized_project_name += '/';

            }
            else {

                normalized_project_name += i;

            }

        }

        return normalized_project_name.split('/');

    }

    add_project(project){

        let project_name = path.normalize(project.name);

        let normalized_project_name = '';

        for(let i of project_name){

            if (i == '\\') {

                normalized_project_name += '/';

            }
            else {

                normalized_project_name += i;

            }

        }

        let project_path = normalized_project_name.split('/');

        project.path = project_path;

        this.projects[project_path] = project;

    }

    get_project(project_name){

        return this.projects[this.get_project_path(project_name)];

    }

    is_have_project(project_name){

        return this.projects.hasOwnProperty(this.get_project_path(project_name));

    }

    get_normalized_cpp_obj_name(cpp_obj_name){

        let parsed_cpp_obj_name = '';

        let isInTemplate = false;

        for(let i of cpp_obj_name){

            if(i == ' ') continue;

            if(!isInTemplate){

                if(i == '<'){

                    isInTemplate = true;

                    continue;

                }

            }
            else{

                if(i == '>'){

                    isInTemplate = false;

                    continue;

                }

            }

            if(!isInTemplate){

                parsed_cpp_obj_name += i;

            }

        }

        return parsed_cpp_obj_name;

    }

    get_cpp_obj_path(cpp_obj_name){

        return this.get_normalized_cpp_obj_name(cpp_obj_name).split('::');

    }

    add_cpp_obj(_cpp_obj){

        let cpp_obj_path = this.get_cpp_obj_path(_cpp_obj.name);

        _cpp_obj.path = cpp_obj_path;

        this.cpp_objects[cpp_obj_path] = _cpp_obj;

    }

    get_cpp_obj(cpp_obj_name){

        return this.cpp_objects[this.get_cpp_obj_path(cpp_obj_name)];

    }

    is_have_cpp_obj(cpp_obj_name){

        return this.cpp_objects.hasOwnProperty(this.get_cpp_obj_path(cpp_obj_name));

    }

    md_add_links(file_content, curr_file_path){

        let result = file_content;

        for(let cpp_obj_path of this.cpp_obj_paths){

            let cpp_obj_name = this.get_normalized_cpp_obj_name(this.get_cpp_obj(cpp_obj_path).name);

            let cpp_obj_path_in_arr = this.get_cpp_obj_path(cpp_obj_name);

            let curr_to_root_path = '';
            for (let i = 0; i < curr_file_path.length - 1; i++){

                curr_to_root_path += '../';

            }

            let cpp_obj_file_path = './' + curr_to_root_path + '/' + this.md_get_abs_file_path(cpp_obj_path_in_arr);

            let replaced_result = '';

            let currSearch = 0;

            let replacedName = `[**${cpp_obj_name}**](${cpp_obj_file_path})`;

            for(let i = 0; i < result.length - cpp_obj_name.length;){

                if(result.substring(i, cpp_obj_name.length + i) == cpp_obj_name){

                    let startSplitI = i;
                    let endSplitI = cpp_obj_name.length + i - 1;

                    let regex = /^[a-zA-Z0-9]+$/;

                    if(!(result[endSplitI + 1].match(regex) || result[endSplitI + 1] == "_" || (result[endSplitI + 1] == ":" && result[endSplitI + 2] == ":"))){

                        replaced_result += replacedName;

                    }
                    else{

                        replaced_result += cpp_obj_name;

                    }

                    i = endSplitI + 1;

                }
                else{

                    replaced_result += result[i];
                    i++;

                }

            }

            result = replaced_result;

        }

        return result;
    }

    md_get_cpp_obj_file_content(_cpp_obj){

        let for_showing_cpp_obj_name = '';

        for(let i = 0; i < _cpp_obj.name.length; i++){

            if(i != _cpp_obj.name.length - 1){

                if(_cpp_obj.name[i] == '<'){

                    for_showing_cpp_obj_name += ' < ';

                }
                else if(_cpp_obj.name[i] == '>'){

                    for_showing_cpp_obj_name += ' > ';

                }
                else {

                    for_showing_cpp_obj_name += _cpp_obj.name[i];

                }

            }
            else{

                if(_cpp_obj.name[i] == '<'){

                    for_showing_cpp_obj_name += ' <';

                }
                else if(_cpp_obj.name[i] == '>'){

                    for_showing_cpp_obj_name += ' >';

                }
                else{

                    for_showing_cpp_obj_name += _cpp_obj.name[i];
                    
                }

            }

        }

        let result = '';

        if(_cpp_obj.type == 'struct'){

            

        }
        else {

            result = (
`
# ${for_showing_cpp_obj_name} #
                
## **Basic Info** ##
- `+'`'+`Description`+'`'+` **:** ${_cpp_obj.description}
- `+'`'+`Parent`+'`'+` **:** ${_cpp_obj.parent}
- `+'`'+`Project`+'`'+` **:** **${_cpp_obj.project}**
            `);
                
            let is_have_property = false;
            let is_have_method = false;
    
            if(_cpp_obj.properties != null)
                if(_cpp_obj.properties.length != 0){
    
                    is_have_property = true;
    
                }
    
            if(_cpp_obj.methods != null)
                if(_cpp_obj.methods.length != 0){
    
                    is_have_method = true;
    
                }
    
            if(is_have_method || is_have_property){

                let member_count = 0;

                if(is_have_method){

                    member_count += _cpp_obj.methods.length;

                }

                if(is_have_property){

                    member_count += _cpp_obj.properties.length;

                }
    
                if(member_count > 1) {
                    result += (
`        
## **Members** ##
                    `);
                }
                else{
                    result += (
`        
## **Member** ##
                    `);
                }
    
            }
    
            if(is_have_property){
    
                result += (
`
- `+'`'+`Property`+'`'+` **:**
    
                `);

                for(let property of _cpp_obj.properties){

                    let description_text = ``;

                    if(property.description != '' && property.description != null){

                        description_text = ` **:** ${property.description}`;

                    }

                    result += (
`
    + ${property.type} **${property.name}** ${description_text}
        
                    `);

                    if(property.getters != null){

                        if(property.getters.length != 0){

                            if(property.getters.length == 1){

                                result += (
`
        + `+'`'+`Getter`+'`'+` :
                                            
                                `);

                            }
                            else{

                                result += (
`
        + `+'`'+`Getters`+'`'+` :
                                    
                                `);

                            }

                            for(let getter of property.getters){

                                let description_text = ``;

                                if(getter.description != '' && getter.description != null){
            
                                    description_text = ` **:** ${getter.description}`;
            
                                }

                                result += (
`
            + ${getter.code} ${description_text}
                                    
                                `);

                            }

                        }

                    }

                    

                    if(property.setters != null){

                        if(property.setters.length != 0){

                            if(property.setters.length == 1){

                                result += (
`
        + `+'`'+`Setter`+'`'+` :
                                            
                                `);

                            }
                            else{

                                result += (
`
        + `+'`'+`Setters`+'`'+` :
                                    
                                `);

                            }

                            for(let setter of property.setters){

                                let description_text = ``;

                                if(setter.description != '' && setter.description != null){
            
                                    description_text = ` **:** ${setter.description}`;
            
                                }

                                result += (
`
            + ${setter.code} ${description_text}
                                    
                                `);

                            }

                        }

                    }

                    if(property.item_getters != null){

                        if(property.item_getters.length != 0){

                            if(property.item_getters.length == 1){

                                result += (
`
        + `+'`'+`Item Getter`+'`'+` :
                                            
                                `);

                            }
                            else{

                                result += (
`
        + `+'`'+`Item Getters`+'`'+` :
                                    
                                `);

                            }

                            for(let item_getter of property.item_getters){

                                let description_text = ``;

                                if(item_getter.description != '' && item_getter.description != null){
            
                                    description_text = ` **:** ${item_getter.description}`;
            
                                }

                                result += (
`
            + ${item_getter.code} ${description_text}
                                    
                                `);

                            }

                        }

                    }

                    

                    if(property.item_setters != null){

                        if(property.item_setters.length != 0){

                            if(property.item_setters.length == 1){

                                result += (
`
        + `+'`'+`Item Setter`+'`'+` :
                                            
                                `);

                            }
                            else{

                                result += (
`
        + `+'`'+`Item Setters`+'`'+` :
                                    
                                `);

                            }

                            for(let item_setter of property.item_setters){

                                let description_text = ``;

                                if(item_setter.description != '' && item_setter.description != null){
            
                                    description_text = ` **:** ${item_setter.description}`;
            
                                }

                                result += (
`
            + ${item_setter.code} ${description_text}
                                    
                                `);

                            }

                        }

                    }

                }
    
            }

            if(is_have_method){
    
                result += (
`
- `+'`'+`Method`+'`'+` **:**
    
                `);

                for(let method of _cpp_obj.methods){

                    let description_text = ``;

                    if(method.description != '' && method.description != null){

                        description_text = ` **:** ${method.description}`;

                    }

                    result += (
`
    + ${method.code} ${description_text}
                        
                    `);

                }

            }

            let is_have_macro = false;

            if(_cpp_obj.macros != null)
                if(_cpp_obj.macros.length != 0){

                    is_have_macro = true;

                }

            if(is_have_macro){

                if(_cpp_obj.macros.length > 1) {
                    result += (
`        
## **Macros** ##
                    `);
                }
                else{
                    result += (
`        
## **Macro** ##
                    `);
                }

                for(let macro of _cpp_obj.macros){

                    let description_text = ``;

                    if(macro.description != '' && macro.description != null){

                        description_text = ` **:** ${macro.description}`;

                    }

                    result += (
`
+ ${macro.code} ${description_text}
                        
                    `);

                }

            }

        }
    
        result = this.md_add_links(result, this.get_cpp_obj_path(this.get_normalized_cpp_obj_name(_cpp_obj.name)));

        return result;

    }

    md_get_file_path(path_array){

        let cpp_obj_md_file_path = path.join(this.global_scope_dir,...path_array);

        cpp_obj_md_file_path += '.md';

        return cpp_obj_md_file_path;
    }

    md_get_abs_file_path(path_array){

        let cpp_obj_md_file_path = path.join(...path_array);

        cpp_obj_md_file_path += '.md';

        return cpp_obj_md_file_path;
    }

    md_create_cpp_obj_files(){

        for(let cpp_obj_path of this.cpp_obj_paths){

            let _cpp_obj = this.get_cpp_obj(cpp_obj_path);

            let cpp_obj_md_file_path = this.md_get_file_path(_cpp_obj.path);

            let cpp_obj_md_file_content = this.md_get_cpp_obj_file_content(_cpp_obj);

            fs.writeFileSync(cpp_obj_md_file_path, cpp_obj_md_file_content);

        }

    }

    build(argv){

        this.clear();

        if(argv.length <= 3){

            console.error(new Error('documentation directory path is null'));

            return false;
        }

        var builder = this;

        this.global_scope_dir = argv[3];

        file_foreach(this.global_scope_dir, (file_path)=>{

            if(is_json_file(file_path)){

                const items = require(file_path);

                if(items.projects != null)
                    for(let project of items.projects){

                        builder.add_project(project);

                    }

                if(items.cpp_objects != null)
                    for(let _cpp_obj of items.cpp_objects){

                        builder.add_cpp_obj(_cpp_obj);

                    }

            }

        });

        this.cpp_obj_paths = Object.keys(this.cpp_objects);

        this.project_paths = Object.keys(this.projects);

        this.md_create_cpp_obj_files();

        return true;
    }

})();