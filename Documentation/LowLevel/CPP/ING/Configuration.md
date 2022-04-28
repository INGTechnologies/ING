
# [**ING::Configuration**](./..//ING/Configuration.md) #
                
## **Basic Info** ##
- `Description` **:** as it name
- `Parent` **:** None
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **Configuration**() 
                        
                            
- `Destructor` **:**
                
    + **~Configuration**() 
                    
                
- `Property` **:**
    
                
    + std::map < std::string, void* >  **ptrMap** 
        
                    
        + `Getter` :
                                            
                                
            + T **Get**<T>(const std::string& name) 
                                    
                                
        + `Setter` :
                                            
                                
            + void **Set**<T>(const std::string& name, T data) 
                                    
                                
- `Method` **:**
    
                
    + bool **Exist**(const std::string& name) 
                        
                    
    + void **Add**(const std::string& name, unsigned int size)  **:** add new configuration property by name and size
                        
                    
    + void **Add** < T > (const std::string& name)  **:** add new configuration property by name and property type
                        
                    