
module.exports = (file_name)=>{

    let parts = file_name.split('.');

    return(parts[parts.length - 1] == 'json');

}