
# [**ING::IApplication**](./..//ING/IApplication.md) #
                
## **Basic Info** ##
- `Description` **:** represents an application
- `Parent` **:** None
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Friend` **:**
                    
    + class [**ING::ApplicationManager**](./..//ING/ApplicationManager.md)
                        
                            
- `Constructor` **:**
                    
    + **IApplication**() 
                        
                            
- `Destructor` **:**
                
    + **~IApplication**() 
                    
                
- `Property` **:**
    
                
    + ING::Utils::String **name** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Utils::String **GetName**() 
                                    
                                
    + ING::Utils::String **configPath** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Utils::String **GetConfigPath**() 
                                    
                                
    + [**ING::Configuration**](./..//ING/Configuration.md)* **configuration** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::Configuration**](./..//ING/Configuration.md)* **GetConfiguration**() 
                                    
                                
    + [**ING::ApplicationWindowManager**](./..//ING/ApplicationWindowManager.md)* **windowManager** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::ApplicationWindowManager**](./..//ING/ApplicationWindowManager.md)* **GetWindowManager**() 
                                    
                                
    + [**ING::ApplicationRenderingSystem**](./..//ING/ApplicationRenderingSystem.md)* **renderingSystem** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::ApplicationRenderingSystem**](./..//ING/ApplicationRenderingSystem.md)* **GetRenderingSystem**() 
                                    
                                
    + std::unordered_map < ING::Utils::String, unsigned int >  **name2ComponentIndexMap** 
        
                    
    + std::vector < IApplicationComponent* >  **componentVector** 
        
                    
        + `Item Getters` :
                                    
                                
            + ING::IApplicationComponent* **GetComponent**(const ING::Utils::String& name)  **:** get component by name
                                    
                                
            + ING::IApplicationComponent* **GetComponent**(unsigned int index)  **:** get component by index
                                    
                                
- `Method` **:**
    
                
    + virtual bool **Init**()  **:** init application
                        
                    
    + virtual void **Release**()  **:** release application
                        
                    
    + void **Start**()  **:** called when the engine start running, it will call **Start** method of each component
                        
                    
    + void **PreUpdate**()  **:** called before **Update**, it will call **PreUpdate** method of each component
                        
                    
    + void **Update**()  **:** called every frame, it will call **Update** method of each component
                        
                    
    + void **LateUpdate**()  **:** called after **Update**, it will call **LateUpdate** method of each component
                        
                    
    + void **PreRender**()  **:** called before **Render**, it will call **PreRender** method of each component
                        
                    
    + void **Render**()  **:** called when the engine rendering, it will call **Render** method of each component
                        
                    
    + void **LateRender**()  **:** called after **Render**, it will call **LateRender** method of each component
                        
                    