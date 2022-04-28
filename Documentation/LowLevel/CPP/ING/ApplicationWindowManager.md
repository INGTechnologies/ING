
# [**ING::ApplicationWindowManager**](./..//ING/ApplicationWindowManager.md) #
                
## **Basic Info** ##
- `Description` **:** Manages all windows of an application
- `Parent` **:** ING::IApplicationComponent
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **ApplicationWindowManager**([**ING::IApplication**](./..//ING/IApplication.md)* application) 
                        
                            
- `Destructor` **:**
                
    + **~ApplicationWindowManager**() 
                    
                
- `Property` **:**
    
                
    + std::unordered_map < std::string,ING::IWindow* >  **name2WindowMap**  **:** name to window map
        
                    
        + `Getter` :
                                            
                                
            + ING::IWindow* **GetWindow**(const std::string& name)  **:** get window by name
                                    
                                
- `Method` **:**
    
                
    + virtual bool **Init**()  **:** overrided from ING::IApplicationComponent::**Init**()
                        
                    
    + virtual void **Release**()  **:** overrided from ING::IApplicationComponent::**Release**()
                        
                    
    + void **Start**()  **:** overrided from ING::IApplicationComponent::**Start**()
                        
                    
    + void **PreUpdate**()  **:** overrided from ING::IApplicationComponent::**PreUpdate**()
                        
                    
    + void **Update**()  **:** overrided from ING::IApplicationComponent::**Update**()
                        
                    
    + void **LateUpdate**()  **:** overrided from ING::IApplicationComponent::**LateUpdate**()
                        
                    
    + void **PreRender**()  **:** overrided from ING::IApplicationComponent::**PreRender**()
                        
                    
    + void **Render**()  **:** overrided from ING::IApplicationComponent::**Render**()
                        
                    
    + void **LateRender**()  **:** overrided from ING::IApplicationComponent::**LateRender**()
                        
                    
    + void **AddWindow**(ING::IWindow* window)  **:** add new window for managing
                        
                    
    + void **RemoveWindow**(ING::IWindow* window)  **:** remove a window that is currently managed
                        
                    