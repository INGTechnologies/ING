
# [**ING::IApplication**](./..//ING\IApplication.md) #
                
## **Basic Info** ##
- `Description` **:** represents an application
- `Parent` **:** None
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Friend` **:**
                    
    + class [**ING::ApplicationManager**](./..//ING\ApplicationManager.md)
                        
                            
- `Constructor` **:**
                    
    + **IApplication**() 
                        
                            
- `Destructor` **:**
                
    + **~IApplication**() 
                    
                
- `Property` **:**
    
                
    + std::string **name** 
        
                    
        + `Getter` :
                                            
                                
            + std::string **GetName**() 
                                    
                                
    + std::string **configPath** 
        
                    
        + `Getter` :
                                            
                                
            + std::string **GetConfigPath**() 
                                    
                                
    + [**ING::Configuration**](./..//ING\Configuration.md)* **configuration** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::Configuration**](./..//ING\Configuration.md)* **GetConfiguration**() 
                                    
                                
    + [**ING::ApplicationWindowManager**](./..//ING\ApplicationWindowManager.md)* **windowManager** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::ApplicationWindowManager**](./..//ING\ApplicationWindowManager.md)* **GetWindowManager**() 
                                    
                                
    + [**ING::ApplicationRenderingSystem**](./..//ING\ApplicationRenderingSystem.md)* **renderingSystem** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::ApplicationRenderingSystem**](./..//ING\ApplicationRenderingSystem.md)* **GetRenderingSystem**() 
                                    
                                
    + std::unordered_map < std::string, unsigned int >  **name2ComponentIndexMap** 
        
                    
    + std::vector < IApplicationComponent* >  **componentVector** 
        
                    
        + `Item Getters` :
                                    
                                
            + ING::IApplicationComponent* **GetComponent**(const std::string& name)  **:** get component by name
                                    
                                
            + ING::IApplicationComponent* **GetComponent**(unsigned int index)  **:** get component by index
                                    
                                
- `Method` **:**
    
                
    + virtual bool **Init**()  **:** init application
                        
                    
    + virtual void **Release**()  **:** release application
                        
                    
    + void **Start**()  **:** called when the engine start running, it will call **Start** method of each application
                        
                    
    + void **PreUpdate**()  **:** called before **Update**, it will call **PreUpdate** method of each application
                        
                    
    + void **Update**()  **:** called every frame, it will call **Update** method of each application
                        
                    
    + void **LateUpdate**()  **:** called after **Update**, it will call **LateUpdate** method of each application
                        
                    
    + void **PreRender**()  **:** called before **Render**, it will call **PreRender** method of each application
                        
                    
    + void **Render**()  **:** called when the engine rendering, it will call **Render** method of each application
                        
                    
    + void **LateRender**()  **:** called after **Render**, it will call **LateRender** method of each application
                        
                    