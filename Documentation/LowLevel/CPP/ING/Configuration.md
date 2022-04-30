
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
    
                
    + std::map < ING::Utils::String, void* >  **ptrMap** 
        
                    
        + `Getter` :
                                            
                                
            + T **Get**<T>(const ING::Utils::String& name) 
                                    
                                
        + `Setter` :
                                            
                                
            + void **Set**<T>(const ING::Utils::String& name, T data) 
                                    
                                
- `Method` **:**
    
                
    + bool **Exist**(const ING::Utils::String& name) 
                        
                    
    + void **Add**(const ING::Utils::String& name, unsigned int size)  **:** add new configuration property by name and size
                        
                    
    + void **Add** < T > (const ING::Utils::String& name)  **:** add new configuration property by name and property type
                        
                    